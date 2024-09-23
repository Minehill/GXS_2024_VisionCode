#include <rclcpp/rclcpp.hpp>
#include <qrmsg/srv/qr.hpp>
#include <opencv2/opencv.hpp>
#include <vector>
class SearchResponse : public rclcpp::Node 
{
    public:
    SearchResponse(std::string name) : Node(name) 
    {
        RCLCPP_INFO(this->get_logger(), "节点已启动：%s.", name.c_str());
        getParams();
        // 打开摄像头
        cap.open(0, cv::CAP_V4L);
        while (!cap.isOpened()) 
        {
            RCLCPP_INFO(this->get_logger(), "摄像头打开失败");
            // 关闭进程
            rclcpp::shutdown();
        }
        // 创建服务
        // std::placeholders::_1, std::placeholders::_2为占位符，表示绑定函数的两个参数（请求、响应）
        search_block_server_ =
        this->create_service<qrmsg::srv::Qr>(
            "QrCallSearch",
            std::bind(&SearchResponse::handle_searchblock, this,
                    std::placeholders::_1, std::placeholders::_2));
    }

    void getParams()
    {
        // 获取参数
        hsv_lower_1 = this->declare_parameter<std::vector<long int>>("1_hsv.lower", std::vector<long int>{0, 0, 0});
        hsv_upper_1 = this->declare_parameter<std::vector<long int>>("1_hsv.upper", std::vector<long int>{0, 0, 0});
        hsv_lower_2 = this->declare_parameter<std::vector<long int>>("2_hsv.lower", std::vector<long int>{0, 0, 0});
        hsv_upper_2 = this->declare_parameter<std::vector<long int>>("2_hsv.upper", std::vector<long int>{0, 0, 0});
        hsv_lower_3 = this->declare_parameter<std::vector<long int>>("3_hsv.lower", std::vector<long int>{0, 0, 0});
        hsv_upper_3 = this->declare_parameter<std::vector<long int>>("3_hsv.upper", std::vector<long int>{0, 0, 0});
        if_debug = this->declare_parameter<bool>("if_debug", false);
    }

    cv::Mat frame;
    // 声明摄像头
    cv::VideoCapture cap;
    std::vector<long int> hsv_lower_1;
    std::vector<long int> hsv_upper_1;
    std::vector<long int> hsv_lower_2;
    std::vector<long int> hsv_upper_2;
    std::vector<long int> hsv_lower_3;
    std::vector<long int> hsv_upper_3;
    std::vector<long int> hsv_lower;
    std::vector<long int> hsv_upper;
    bool if_debug;
     

    private:
    // 收到请求的处理函数
    void handle_searchblock
        (
        const std::shared_ptr<qrmsg::srv::Qr::Request> request,
        std::shared_ptr<qrmsg::srv::Qr::Response> response
        ) 
    {
        RCLCPP_INFO(this->get_logger(), "收到num: %ld way: %ld", request->num,request->way);
        if(request->num == 1)
        {
            hsv_lower = hsv_lower_1;
            hsv_upper = hsv_upper_1;
        }
        else if(request->num == 2)
        {
            hsv_lower = hsv_lower_2;
            hsv_upper = hsv_upper_2;
        }
        else if(request->num == 3)
        {
            hsv_lower = hsv_lower_3;
            hsv_upper = hsv_upper_3;
        }


        bool if_find = false;
        bool if_lock = false;
        cv::Point2f pre_center = cv::Point2f(0, 0);
        // 显示摄像头的画面
        while(!if_find)
        {
            cap.read(frame);
            
            // 寻找HSV色域范围在指定范围内的物体
            cv::Mat hsv;
            cv::cvtColor(frame, hsv, cv::COLOR_BGR2HSV);
            cv::Mat mask;
            cv::inRange(hsv, cv::Scalar(hsv_lower[0], hsv_lower[1], hsv_lower[2]), cv::Scalar(hsv_upper[0], hsv_upper[1], hsv_upper[2]), mask);

            // 将色域过滤后的最大面积物体找出，并返回外接矩形四角坐标并绘制
            std::vector<std::vector<cv::Point>> contours;
            cv::findContours(mask, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
            if (contours.size() > 0) 
            {
                std::vector<cv::Point> max_contour = contours[0];
                for (size_t i = 1; i < contours.size(); i++) 
                {
                    if (cv::contourArea(contours[i]) > cv::contourArea(max_contour)) 
                    {
                        max_contour = contours[i];
                    }
                }
                cv::RotatedRect rect = cv::minAreaRect(max_contour);
                cv::Point2f vertices[4];
                rect.points(vertices);
                for (int i = 0; i < 4; i++) 
                {
                    cv::line(frame, vertices[i], vertices[(i + 1) % 4], cv::Scalar(0, 255, 0), 2);
                }
                // 计算中心点坐标
                cv::Point2f center = rect.center;
                // 计算中心点坐标与图像中心点坐标的差值
                cv::Point2f diff = center - cv::Point2f(frame.cols / 2, frame.rows / 2);
                // 计算差值的模
                double distance = cv::norm(diff);
                // 计算差值的角度
                double angle = atan2(diff.y, diff.x) * 180 / CV_PI;
                
                if (if_debug)
                {
                    // 显示中心点
                    cv::circle(frame, center, 5, cv::Scalar(0, 255, 0), -1);
                    // 显示差值
                    cv::putText(frame, "Distance: " + std::to_string(distance), cv::Point(10, 30), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 255, 0), 2);
                    cv::putText(frame, "Angle: " + std::to_string(angle), cv::Point(10, 60), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 255, 0), 2);
                    // 显示面积
                    cv::putText(frame, "Area: " + std::to_string(cv::contourArea(max_contour)), cv::Point(10, 90), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 255, 0), 2);
                    // 显示图像
                    cv::imshow("Frame", frame);
                    cv::imshow("Mask", mask);
                    cv::imshow("Frame", frame);
                    cv::waitKey(1);
                }
                
                // 若外接矩形面积大于指定值，则认为找到目标
                if (cv::contourArea(max_contour) > 12000) 
                {
                    if_lock = true;
                    // if_find = true;
                    // 摧毁所有的窗口
                    // cv::destroyAllWindows();
                }
                else
                {
                    if_lock = false;
                }
                // 若中心点坐标与前一帧中心点坐标的差值小于指定值，则认为找到目标
                if (if_lock && cv::norm(center - pre_center) < 1) 
                {
                    if_find = true;
                    response->dis = pnp_solve(rect);
                    // 摧毁所有的窗口
                    cv::destroyAllWindows();
                }
                else
                {
                    pre_center = center;
                }
            }
        }
       
        response->finish = true;
        response->way = request->way;
    }
    
    // pnp求解目标距离
    float pnp_solve(cv::RotatedRect rect)
    {
        // 假设这些参数已知
        double actual_width = 0.1; // 目标物体的实际宽度，单位：米
        double actual_height = 0.05; // 目标物体的实际高度，单位：米
        double fx = 800; // 相机的焦距，单位：像素
        double fy = 800; // 相机的焦距，单位：像素
        double cx = 320; // 相机的主点x坐标
        double cy = 240; // 相机的主点y坐标
        double k1 = 0, k2 = 0, p1 = 0, p2 = 0, k3 = 0; // 畸变系数

        // 获取矩形的四个顶点
        cv::Point2f rect_points[4];
        rect.points(rect_points);

        // 定义图像中的2D坐标
        std::vector<cv::Point2f> image_points;
        for (int i = 0; i < 4; i++) {
            image_points.push_back(rect_points[i]);
        }

        // 定义目标物体在世界坐标系中的3D坐标
        std::vector<cv::Point3f> object_points;
        object_points.push_back(cv::Point3f(-actual_width/2, -actual_height/2, 0)); // 左下角
        object_points.push_back(cv::Point3f(actual_width/2, -actual_height/2, 0));  // 右下角
        object_points.push_back(cv::Point3f(actual_width/2, actual_height/2, 0));   // 右上角
        object_points.push_back(cv::Point3f(-actual_width/2, actual_height/2, 0));  // 左上角

        // 定义相机内参矩阵和畸变系数
        cv::Mat camera_matrix = (cv::Mat_<double>(3, 3) << fx, 0, cx, 0, fy, cy, 0, 0, 1);
        cv::Mat dist_coeffs = (cv::Mat_<double>(1, 5) << k1, k2, p1, p2, k3);

        // 定义旋转向量和平移向量
        cv::Mat rvec, tvec;

        // 使用solvePnP求解位姿
        cv::solvePnP(object_points, image_points, camera_matrix, dist_coeffs, rvec, tvec);

        // 计算目标物体的距离
        float distance = cv::norm(tvec);
        return distance;
    }

    // 声明服务
    rclcpp::Service<qrmsg::srv::Qr>::SharedPtr search_block_server_;
};


int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SearchResponse>("BlockSearch"));
    rclcpp::shutdown();
    return 0;
}