#include <rclcpp/rclcpp.hpp>
#include <qrmsg/srv/qr.hpp>
#include <opencv2/opencv.hpp>

class SearchResponse : public rclcpp::Node 
{
    public:
    cv::Mat frame;
    // 声明摄像头
    cv::VideoCapture cap;
    SearchResponse(std::string name) : Node(name) 
    {
        RCLCPP_INFO(this->get_logger(), "节点已启动：%s.", name.c_str());
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

    private:
    // 收到请求的处理函数
    void handle_searchblock
        (
        const std::shared_ptr<qrmsg::srv::Qr::Request> request,
        std::shared_ptr<qrmsg::srv::Qr::Response> response
        ) 
    {
        RCLCPP_INFO(this->get_logger(), "收到num: %ld way: %ld", request->num,request->way);
        bool if_find = false;
        bool if_lock = false;
        cv::Point2f pre_center = cv::Point2f(0, 0);
        // 显示摄像头的画面
        while(!if_find)
        {
            cap.read(frame);
            cv::imshow("Frame", frame);
            // 寻找HSV色域范围在指定范围内的物体
            cv::Mat hsv;
            cv::cvtColor(frame, hsv, cv::COLOR_BGR2HSV);
            cv::Mat mask;
            cv::inRange(hsv, cv::Scalar(45, 115, 50), cv::Scalar(180, 255, 160), mask);
            cv::imshow("Mask", mask);
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
                // 显示中心点
                cv::circle(frame, center, 5, cv::Scalar(0, 255, 0), -1);
                // 显示差值
                cv::putText(frame, "Distance: " + std::to_string(distance), cv::Point(10, 30), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 255, 0), 2);
                cv::putText(frame, "Angle: " + std::to_string(angle), cv::Point(10, 60), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 255, 0), 2);
                // 显示面积
                cv::putText(frame, "Area: " + std::to_string(cv::contourArea(max_contour)), cv::Point(10, 90), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 255, 0), 2);
                // 显示图像
                cv::imshow("Frame", frame);
                cv::waitKey(1);
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
                    // 摧毁所有的窗口
                    cv::destroyAllWindows();
                }
                else
                {
                    pre_center = center;
                }
            }
            response->finish = true;
            response->way = request->way;
        }
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