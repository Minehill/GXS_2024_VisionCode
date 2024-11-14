#include <rclcpp/rclcpp.hpp>
#include <qrmsg/srv/qr.hpp>
#include <qrmsg/msg/qr.hpp>
#include <opencv2/opencv.hpp>
#include <vector>
#include <geometry_msgs/msg/vector3.hpp>
#include <iostream>
#include <sensor_msgs/msg/image.hpp>
#include <cv_bridge/cv_bridge.h>

class SearchResponse : public rclcpp::Node 
{
    public:
    SearchResponse(std::string name) : Node(name) 
    {
        RCLCPP_INFO(this->get_logger(), "节点已启动：%s.", name.c_str());
        getParams();
        // 打开摄像头
        /*
        cap.open(0, cv::CAP_V4L);
        while (!cap.isOpened()) 
        {
            RCLCPP_INFO(this->get_logger(), "摄像头打开失败");
            // 关闭进程
            rclcpp::shutdown();
        }
        */

        // 创建服务
        // std::placeholders::_1, std::placeholders::_2为占位符，表示绑定函数的两个参数（请求、响应）
        /*
        search_block_server_ =
        this->create_service<qrmsg::srv::Qr>(
            "QrCallSearch",
            std::bind(&SearchResponse::handle_searchblock, this,
                    std::placeholders::_1, std::placeholders::_2));
        */
        // 创建二维码请求订阅者
        request_sub = this->create_subscription<qrmsg::msg::Qr>(
            "/request", 10,
            std::bind(&SearchResponse::searchblock, this, std::placeholders::_1));

        // 创建位姿发布者
        colorblock_pos_pub = this->create_publisher<geometry_msgs::msg::Vector3>("colorblock_pos", 10);
        
        // 创建图像订阅者
        img_subscriber_ = this->create_subscription<sensor_msgs::msg::Image>(
            "image_topic", 10,
            std::bind(&SearchResponse::image_callback, this, std::placeholders::_1));
        /*
        // 启动多线程执行器    
        executor_ = std::make_shared<rclcpp::executors::MultiThreadedExecutor>();
        executor_->add_node(this->get_node_base_interface());
        */
    }
   
    

    void getParams()
    {

        // 获取参数
        hsv_lower_1 = this->declare_parameter<std::vector<long int>>("1_hsv_lower", std::vector<long int>{98, 240, 0});
        hsv_upper_1 = this->declare_parameter<std::vector<long int>>("1_hsv_upper", std::vector<long int>{105, 255, 255});

        hsv_lower_2 = this->declare_parameter<std::vector<long int>>("2_hsv_lower", std::vector<long int>{90, 240, 0});
        hsv_upper_2 = this->declare_parameter<std::vector<long int>>("2_hsv_upper", std::vector<long int>{98, 255, 255});
        
        hsv_lower_3 = this->declare_parameter<std::vector<long int>>("3_hsv_lower", std::vector<long int>{170, 180, 0});
        hsv_upper_3 = this->declare_parameter<std::vector<long int>>("3_hsv_upper", std::vector<long int>{180, 255, 255});
        if_debug = this->declare_parameter<bool>("if_debug", true);
    }

    cv::Mat frame;
    cv::Mat frame_;
    // 声明摄像头
    // cv::VideoCapture cap;
    // 声明HSV色域范围
    std::vector<long int> hsv_lower_1;
    std::vector<long int> hsv_upper_1;
    std::vector<long int> hsv_lower_2;
    std::vector<long int> hsv_upper_2;
    std::vector<long int> hsv_lower_3;
    std::vector<long int> hsv_upper_3;
    std::vector<long int> hsv_lower;
    std::vector<long int> hsv_upper;
    bool if_debug;
    // 声明发布者，发布PNP解算后的距离
    rclcpp::Publisher<geometry_msgs::msg::Vector3>::SharedPtr colorblock_pos_pub;
    // 声明订阅者，订阅图像消息
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr img_subscriber_;
    // 声明多线程执行器
    std::shared_ptr<rclcpp::executors::MultiThreadedExecutor> executor_;
    // 声明请求订阅者
    rclcpp::Subscription<qrmsg::msg::Qr>::SharedPtr request_sub;

    private:
    // 订阅图像的回调函数
    void image_callback(const sensor_msgs::msg::Image::SharedPtr msg) {
       // 将 ROS 图像消息转换为 OpenCV 图像
       cv_bridge::CvImagePtr cv_ptr = cv_bridge::toCvCopy(msg, "bgr8");
       frame_ = cv_ptr->image;


       // RCLCPP_INFO(this->get_logger(), "收到图像");
    //    if(frame_.empty())
    //    {
    //        RCLCPP_INFO(this->get_logger(), "图像为空");
    //    }
    //    else
    //     {
    //         RCLCPP_INFO(this->get_logger(), "图像不为空");
    //     }
        
    }
    
    // 订阅请求的回调函数
    void searchblock(const qrmsg::msg::Qr::SharedPtr msg)
    {
        
        // RCLCPP_INFO(this->get_logger(), "收到num: %ld way: %ld", msg->num,msg->way);
        
        if (msg->is_new)
        {
            if_find = false;
            if_lock = false;
            new_ = true;
            // RCLCPP_INFO(this->get_logger(), "进入is new 分支");
        }
        /*
        else
        {	
            if_find = false;
            if_lock = true;
            new_ = false;
            // RCLCPP_INFO(this->get_logger(), "没有进入");
        }
        */
        
        if(msg->num == 1)
        {
            hsv_lower = hsv_lower_1;
            hsv_upper = hsv_upper_1;
        }
        else if(msg->num == 2)
        {
            hsv_lower = hsv_lower_2;
            hsv_upper = hsv_upper_2;
        }
        else if(msg->num == 3)
        {
            hsv_lower = hsv_lower_3;
            hsv_upper = hsv_upper_3;
        }
        else
        {
            RCLCPP_INFO(this->get_logger(), "colorblock out of index");
            return;
        }

        if (frame_.empty())
        {
            RCLCPP_INFO(this->get_logger(), "进去了，但进不去了");
            return;
        }
        
        // 显示摄像头的画面
        // while(!if_find)
        {
            // RCLCPP_INFO(this->get_logger(), "进入循环");
            // cap.read(frame);
            frame = frame_.clone();
            
            // 寻找HSV色域范围在指定范围内的物体
            cv::Mat hsv;
            cv::cvtColor(frame, hsv, cv::COLOR_BGR2HSV);
            cv::Mat mask;
            cv::inRange(hsv, cv::Scalar(hsv_lower[0], hsv_lower[1], hsv_lower[2]), cv::Scalar(hsv_upper[0], hsv_upper[1], hsv_upper[2]), mask=mask);


            //  侵蚀图像
            cv::Mat erode_kernel = getStructuringElement(cv::MORPH_RECT, cv::Size(15, 15));
            cv::erode(mask, mask, erode_kernel, cv::Point(-1, -1), 2);
            cv::imshow("erode", mask);
            //  扩张
            cv::Mat dia_kernel = getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));
            cv::dilate(mask, mask, dia_kernel);
            cv::imshow("dia", mask);
            

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
                // 绘制轮廓
                // cv::drawContours(mask, std::vector<std::vector<cv::Point>>{max_contour}, 0, cv::Scalar(0, 255, 0), 3);
                // cv::imshow("contours", mask);

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
                    // cv::imshow("Frame", frame);
                    cv::imshow("Mask", mask);
                    cv::imshow("Frame", frame);
                    cv::waitKey(1);
                }
                
                // 若外接矩形面积大于指定值，则认为找到目标
                // lzt : for debug 
                std::cout << cv::contourArea(max_contour);

                // 若面积大于一定值，说明能够锁定目标
                if (cv::contourArea(max_contour) > 2000) 
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
                if (if_lock)
                {
                    if (cv::norm(center - pre_center) < 10000)
                    {
                        if_find = true;
                        double dis = pnp_solve(rect, msg->num);
                    }
                    else if (if_find)
                    {
                        double dis = pnp_solve(rect, msg->num);
                    }
                    else
                    {
                        pre_center = center;
                    }
                }
                
                
                RCLCPP_INFO(this->get_logger(), "find something!");
            }
            else
            {
                RCLCPP_INFO(this->get_logger(), "find nothing!");
            }
            // 主动切换到图像接受的回调函数中
            // RCLCPP_INFO(this->get_logger(), "you should yeild");
            // RCLCPP_INFO(this->get_logger(), "if_find : %d, if_lock : %d", if_find, if_lock);
            // std::this_thread::yield;
        }
        // RCLCPP_INFO(this->get_logger(), "do it");
        // cv::destroyAllWindows();
        // response->finish = true;
        // response->way = request->way;
        // RCLCPP_INFO(this->get_logger(), "do it ~~~~~~~");
    }

    /*
    // 收到请求的处理函数
    void handle_searchblock
        (
        const std::shared_ptr<qrmsg::srv::Qr::Request> request,
        std::shared_ptr<qrmsg::srv::Qr::Response> response
        ) 
    {
        return;
        RCLCPP_INFO(this->get_logger(), "收到num: %ld way: %ld", request->num,request->way);
        
        if (request->is_new)
        {
            if_find = false;
            if_lock = false;
            new_ = true;
            RCLCPP_INFO(this->get_logger(), "进入is new 分支");
        }
        else
        {	
            if_find = false;
            if_lock = true;
            new_ = false;
            RCLCPP_INFO(this->get_logger(), "没有进入");
        }
        
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


        cv::Point2f pre_center = cv::Point2f(0, 0);
        // 显示摄像头的画面
        while(!if_find)
        {
            // cap.read(frame);
            frame = frame_.clone();

            // 寻找HSV色域范围在指定范围内的物体
            cv::Mat hsv;
            cv::cvtColor(frame, hsv, cv::COLOR_BGR2HSV);
            cv::Mat mask;
            cv::inRange(hsv, cv::Scalar(hsv_lower[0], hsv_lower[1], hsv_lower[2]), cv::Scalar(hsv_upper[0], hsv_upper[1], hsv_upper[2]), mask=mask);

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
                    // cv::imshow("Frame", frame);
                    cv::imshow("Mask", mask);
                    cv::imshow("Frame", frame);
                    cv::waitKey(1);
                }
                
                // 若外接矩形面积大于指定值，则认为找到目标
                // lzt : for debug 
                std::cout << cv::contourArea(max_contour);
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
                if (new_)
                {
                    if (if_lock && cv::norm(center - pre_center) < 1) 
                    {
                        if_find = true;
                        response->dis = pnp_solve(rect);
                        // 摧毁所有的窗口
                        // cv::destroyAllWindows();
                        break;
                    }
                    else
                    {
                        pre_center = center;
                    }
                }
                // 找到目标后，由于机械臂在移动，因此无需再进行前后帧对比
                else
                {
                    if_find = true;
                    response->dis = pnp_solve(rect);
                    RCLCPP_INFO(this->get_logger(), "yes it is");
                    // 摧毁所有的窗口
                    // cv::destroyAllWindows();
                    break;
                }
            }
        }
        RCLCPP_INFO(this->get_logger(), "do it");
        cv::destroyAllWindows();
        response->finish = true;
        response->way = request->way;
        RCLCPP_INFO(this->get_logger(), "do it ~~~~~~~");
    }
    */

    // pnp求解目标距离
    float pnp_solve(cv::RotatedRect rect, int number)
    {
        // // 获取矩形的四个顶点
        // cv::Point2f rect_points[4];
        // rect.points(rect_points);

        // // 定义图像中的2D坐标
        // std::vector<cv::Point2f> image_points;
        // for (int i = 0; i < 4; i++)
        // {
        //     image_points.push_back(rect_points[i]);
        // }

        // // 定义物体的3D坐标（假设物体在z=0平面上）
        // std::vector<cv::Point3f> object_points;
        // object_points.push_back(cv::Point3f(-actual_width / 2, -actual_height / 2, 0));
        // object_points.push_back(cv::Point3f(actual_width / 2, -actual_height / 2, 0));
        // object_points.push_back(cv::Point3f(actual_width / 2, actual_height / 2, 0));
        // object_points.push_back(cv::Point3f(-actual_width / 2, actual_height / 2, 0));

        // // 相机内参矩阵
        // cv::Mat camera_matrix = (cv::Mat_<double>(3, 3) << fx, 0, cx, 0, fy, cy, 0, 0, 1);

        // // 畸变系数
        // cv::Mat dist_coeffs = (cv::Mat_<double>(1, 5) << k1, k2, p1, p2, k3);

        // // 输出旋转向量和平移向量
        // cv::Mat rvec, tvec;

        // // 使用solvePnP求解
        // cv::solvePnP(object_points, image_points, camera_matrix, dist_coeffs, rvec, tvec);

        // // 将旋转向量转换为旋转矩阵
        // cv::Mat R;
        // cv::Rodrigues(rvec, R);

        // // 打印旋转矩阵和平移向量
        // // std::cout << "Rotation Matrix: " << R << std::endl;
        // // std::cout << "Translation Vector: " << tvec << std::endl;

        // // 提取平移向量中的x, y, z分量
        // double x = tvec.at<double>(0);
        // double y = tvec.at<double>(1);
        // double z = tvec.at<double>(2);

        // 打印目标物体相对于相机的真实位置
        // std::cout << "Object Position (X, Y, Z): (" << x << ", " << y << ", " << z << ")" << std::endl;
        cv::Point2f rect_center = rect.center;
        double x =  rect_center.x;
        double y =  rect_center.y;
        int z = number;
        // 发布该位姿
        geometry_msgs::msg::Vector3 pos;
        pos.x = x;
        pos.y = y;
        pos.z = z;
        colorblock_pos_pub->publish(pos);
        return z;
    }

    // 假设这些参数已知
    
    // double actual_width = 0.1; // 目标物体的实际宽度，单位：米
    // double actual_height = 0.05; // 目标物体的实际高度，单位：米
    // double fx = 800; // 相机的焦距，单位：像素
    // double fy = 800; // 相机的焦距，单位：像素
    // double cx = 320; // 相机的主点x坐标
    // double cy = 240; // 相机的主点y坐标
    // double k1 = 0, k2 = 0, p1 = 0, p2 = 0, k3 = 0; // 畸变系数

    // 声明服务
    rclcpp::Service<qrmsg::srv::Qr>::SharedPtr search_block_server_;

    // 识别的目标是否找到
    bool if_find = false;
    bool if_lock = false;
    bool new_ = true;
    cv::Point2f pre_center = cv::Point2f(0, 0);
};


int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SearchResponse>("BlockSearch"));
    rclcpp::shutdown();
    return 0;
}
