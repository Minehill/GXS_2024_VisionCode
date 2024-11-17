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
        // 色块阈值
        getParams();
        // 色环阈值
        getParams_();

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
    }
   
    

    void getParams()
    {
        this->declare_parameter<int>("1_h_lower", 0);
        this->declare_parameter<int>("1_s_lower", 0);
        this->declare_parameter<int>("1_v_lower", 0);

        this->declare_parameter<int>("1_h_upper", 255);
        this->declare_parameter<int>("1_s_upper", 255);
        this->declare_parameter<int>("1_v_upper", 255);

        this->declare_parameter<int>("2_h_lower", 0);
        this->declare_parameter<int>("2_s_lower", 0);
        this->declare_parameter<int>("2_v_lower", 0);

        this->declare_parameter<int>("2_h_upper", 255);
        this->declare_parameter<int>("2_s_upper", 255);
        this->declare_parameter<int>("2_v_upper", 255);

        this->declare_parameter<int>("3_h_lower", 0);
        this->declare_parameter<int>("3_s_lower", 0);
        this->declare_parameter<int>("3_v_lower", 0);

        this->declare_parameter<int>("3_h_upper", 255);
        this->declare_parameter<int>("3_s_upper", 255);
        this->declare_parameter<int>("3_v_upper", 255);

        this->declare_parameter<bool>("if_debug", true);

        auto hl1 = this->get_parameter("1_h_lower").as_int();
        auto sl1 = this->get_parameter("1_s_lower").as_int();
        auto vl1 = this->get_parameter("1_v_lower").as_int();

        auto hh1 = this->get_parameter("1_h_upper").as_int();
        auto sh1 = this->get_parameter("1_s_upper").as_int();
        auto vh1 = this->get_parameter("1_v_upper").as_int();

        auto hl2 = this->get_parameter("2_h_lower").as_int();
        auto sl2 = this->get_parameter("2_s_lower").as_int();
        auto vl2 = this->get_parameter("2_v_lower").as_int();

        auto hh2 = this->get_parameter("2_h_upper").as_int();
        auto sh2 = this->get_parameter("2_s_upper").as_int();
        auto vh2 = this->get_parameter("2_v_upper").as_int();

        auto hl3 = this->get_parameter("3_h_lower").as_int();
        auto sl3 = this->get_parameter("3_s_lower").as_int();
        auto vl3 = this->get_parameter("3_v_lower").as_int();

        auto hh3 = this->get_parameter("3_h_upper").as_int();
        auto sh3 = this->get_parameter("3_s_upper").as_int();
        auto vh3 = this->get_parameter("3_v_upper").as_int();

        if_debug = this->get_parameter("if_debug").as_bool();

        hsv_lower_1 = std::vector<long int>{hl1, sl1, vl1};
        hsv_upper_1 = std::vector<long int>{hh1, sh1, vh1};

        hsv_lower_2 = std::vector<long int>{hl2, sl2, vl2};
        hsv_upper_2 = std::vector<long int>{hh2, sh2, vh2};
        
        hsv_lower_3 = std::vector<long int>{hl3, sl3, vl3};
        hsv_upper_3 = std::vector<long int>{hh3, sh3, vh3};
    }

    void getParams_()
    {
        this->declare_parameter<int>("1_h_lower_", 0);
        this->declare_parameter<int>("1_s_lower_", 0);
        this->declare_parameter<int>("1_v_lower_", 0);

        this->declare_parameter<int>("1_h_upper_", 255);
        this->declare_parameter<int>("1_s_upper_", 255);
        this->declare_parameter<int>("1_v_upper_", 255);

        this->declare_parameter<int>("2_h_lower_", 0);
        this->declare_parameter<int>("2_s_lower_", 0);
        this->declare_parameter<int>("2_v_lower_", 0);

        this->declare_parameter<int>("2_h_upper_", 255);
        this->declare_parameter<int>("2_s_upper_", 255);
        this->declare_parameter<int>("2_v_upper_", 255);

        this->declare_parameter<int>("3_h_lower_", 0);
        this->declare_parameter<int>("3_s_lower_", 0);
        this->declare_parameter<int>("3_v_lower_", 0);

        this->declare_parameter<int>("3_h_upper_", 255);
        this->declare_parameter<int>("3_s_upper_", 255);
        this->declare_parameter<int>("3_v_upper_", 255);

        auto hl1 = this->get_parameter("1_h_lower_").as_int();
        auto sl1 = this->get_parameter("1_s_lower_").as_int();
        auto vl1 = this->get_parameter("1_v_lower_").as_int();

        auto hh1 = this->get_parameter("1_h_upper_").as_int();
        auto sh1 = this->get_parameter("1_s_upper_").as_int();
        auto vh1 = this->get_parameter("1_v_upper_").as_int();

        auto hl2 = this->get_parameter("2_h_lower_").as_int();
        auto sl2 = this->get_parameter("2_s_lower_").as_int();
        auto vl2 = this->get_parameter("2_v_lower_").as_int();

        auto hh2 = this->get_parameter("2_h_upper_").as_int();
        auto sh2 = this->get_parameter("2_s_upper_").as_int();
        auto vh2 = this->get_parameter("2_v_upper_").as_int();

        auto hl3 = this->get_parameter("3_h_lower_").as_int();
        auto sl3 = this->get_parameter("3_s_lower_").as_int();
        auto vl3 = this->get_parameter("3_v_lower_").as_int();

        auto hh3 = this->get_parameter("3_h_upper_").as_int();
        auto sh3 = this->get_parameter("3_s_upper_").as_int();
        auto vh3 = this->get_parameter("3_v_upper_").as_int();

        hsv_lower_1_ = std::vector<long int>{hl1, sl1, vl1};
        hsv_upper_1_ = std::vector<long int>{hh1, sh1, vh1};

        hsv_lower_2_ = std::vector<long int>{hl2, sl2, vl2};
        hsv_upper_2_ = std::vector<long int>{hh2, sh2, vh2};
        
        hsv_lower_3_ = std::vector<long int>{hl3, sl3, vl3};
        hsv_upper_3_ = std::vector<long int>{hh3, sh3, vh3};
    }

    cv::Mat frame;
    cv::Mat frame_;
    // 声明摄像头
    // cv::VideoCapture cap;
    // 声明HSV色域范围
    // 色块
    std::vector<long int> hsv_lower_1;
    std::vector<long int> hsv_upper_1;
    std::vector<long int> hsv_lower_2;
    std::vector<long int> hsv_upper_2;
    std::vector<long int> hsv_lower_3;
    std::vector<long int> hsv_upper_3;
    std::vector<long int> hsv_lower;
    std::vector<long int> hsv_upper;
    // 色环
    std::vector<long int> hsv_lower_1_;
    std::vector<long int> hsv_upper_1_;
    std::vector<long int> hsv_lower_2_;
    std::vector<long int> hsv_upper_2_;
    std::vector<long int> hsv_lower_3_;
    std::vector<long int> hsv_upper_3_;
    std::vector<long int> hsv_lower_;
    std::vector<long int> hsv_upper_;
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
        }
        
        if(msg->num == 1)
        {
            hsv_lower = hsv_lower_1;
            hsv_upper = hsv_upper_1;

            hsv_lower_ = hsv_lower_1_;
            hsv_upper_ = hsv_upper_1_;
        }
        else if(msg->num == 2)
        {
            hsv_lower = hsv_lower_2;
            hsv_upper = hsv_upper_2;

            hsv_lower_ = hsv_lower_2_;
            hsv_upper_ = hsv_upper_2_;
        }
        else if(msg->num == 3)
        {
            hsv_lower = hsv_lower_3;
            hsv_upper = hsv_upper_3;

            hsv_lower_ = hsv_lower_3_;
            hsv_upper_ = hsv_upper_3_;
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
        if (msg->way == 0)
        {
            frame = frame_.clone();
            
            // 寻找HSV色域范围在指定范围内的物体
            cv::Mat hsv;
            cv::cvtColor(frame, hsv, cv::COLOR_BGR2HSV);
            cv::Mat mask;
            cv::inRange(hsv, cv::Scalar(hsv_lower[0], hsv_lower[1], hsv_lower[2]), cv::Scalar(hsv_upper[0], hsv_upper[1], hsv_upper[2]), mask=mask);


            //  侵蚀图像
            cv::Mat erode_kernel = getStructuringElement(cv::MORPH_RECT, cv::Size(15, 15));
            cv::erode(mask, mask, erode_kernel, cv::Point(-1, -1), 2);
            // cv::imshow("erode", mask);
            //  扩张
            cv::Mat dia_kernel = getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));
            cv::dilate(mask, mask, dia_kernel);
            // cv::imshow("dia", mask);
            

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
                // std::cout << cv::contourArea(max_contour);

                // 若面积大于一定值，说明能够锁定目标
                if (cv::contourArea(max_contour) > 2000) 
                {
                    if_lock = true;
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
                
                
                // RCLCPP_INFO(this->get_logger(), "find something!");
            }
            // else
            // {
            //    RCLCPP_INFO(this->get_logger(), "find nothing!");
            // }
        }
        else if (msg->way == 1)
        {
            frame = frame_.clone();
            
            // 寻找HSV色域范围在指定范围内的物体
            cv::Mat hsv;
            cv::cvtColor(frame, hsv, cv::COLOR_BGR2HSV);
            cv::Mat mask;
            cv::inRange(hsv, cv::Scalar(hsv_lower_[0], hsv_lower_[1], hsv_lower_[2]), cv::Scalar(hsv_upper_[0], hsv_upper_[1], hsv_upper_[2]), mask=mask);
            // cv::imshow("Mask", mask);
            //  扩张
            cv::Mat dia_kernel = getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));
            cv::dilate(mask, mask, dia_kernel);
            // cv::imshow("dia", mask);

            // 找到所有轮廓
            std::vector<std::vector<cv::Point>> contours;
            cv::findContours(mask, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

            // 找到面积最大的轮廓
            double max_area = 0;
            int max_contour_idx = -1;
            for (size_t i = 0; i < contours.size(); i++)
            {
                double area = cv::contourArea(contours[i]);
                if (area > max_area)
                {
                    max_area = area;
                    max_contour_idx = i;
                }
            }

            if (max_contour_idx != -1)
            {
                // 拟合圆并获取圆心坐标和半径
                cv::Point2f center;
                float radius;
                cv::minEnclosingCircle(contours[max_contour_idx], center, radius);
		if (if_debug)
                {
                // 在图上绘制圆
                cv::circle(frame, center, static_cast<int>(radius), cv::Scalar(0, 255, 0), 2);
                cv::imshow("Frame", frame);

                // 输出圆心坐标
                RCLCPP_INFO(this->get_logger(), "Circle center: (%f, %f)", center.x, center.y);
		}
                // 发布该位姿
                geometry_msgs::msg::Vector3 pos;
                pos.x = center.x;
                pos.y = center.y;
                pos.z = msg->num;
                colorblock_pos_pub->publish(pos);
            }

            // cv::waitKey(1);

        }
    }

    // pnp求解目标距离
    float pnp_solve(cv::RotatedRect rect, int number)
    {

        // 打印目标物体相对于相机的真实位置
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
