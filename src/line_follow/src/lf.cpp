#include <rclcpp/rclcpp.hpp>
#include <opencv2/opencv.hpp>
#include <vector>
#include <geometry_msgs/msg/vector3.hpp>
#include <iostream>
#include <sensor_msgs/msg/image.hpp>
#include <cv_bridge/cv_bridge.h>
#include <qrmsg/msg/lf.hpp>

class LineFollow : public rclcpp::Node 
{
    public:
        LineFollow(const std::string& name) : Node (name)
        {
            RCLCPP_INFO(this->get_logger(), "节点已启动：%s.", name.c_str());

             // 创建图像订阅者
            img_subscriber_ = this->create_subscription<sensor_msgs::msg::Image>(
                "image_topic", 10,
                std::bind(&LineFollow::image_callback, this, std::placeholders::_1));
            // 创建斜率与截距发布者
            lf_publisher_ = this->create_publisher<qrmsg::msg::Lf>("lf_topic", 10);
        }


        // 订阅图像的回调函数
        void image_callback(const sensor_msgs::msg::Image::SharedPtr msg) {
            // 将 ROS 图像消息转换为 OpenCV 图像
            cv_bridge::CvImagePtr cv_ptr = cv_bridge::toCvCopy(msg, "bgr8");
            frame_ = cv_ptr->image;
            if (!frame_.empty())
            {
                FindBlackLine();
            }
        }

        void FindBlackLine()
        {
            // 转换为灰度图像
            cv::Mat gray;
            cv::cvtColor(frame_, gray, cv::COLOR_BGR2GRAY);

            // 二值化
            cv::Mat binary;
            cv::threshold(gray, binary, 100, 255, cv::THRESH_BINARY_INV);

            // 显示二值化结果
            cv::namedWindow("Binary", cv::WINDOW_NORMAL);
            // 修改窗口大小
            cv::resizeWindow("Binary", 800, 600);
            cv::imshow("Binary", binary);

            // 查找所有非0像素点
            std::vector<cv::Point> points;
            cv::findNonZero(binary, points);

            if (points.empty())
            {
                RCLCPP_ERROR(this->get_logger(), "未找到黑色线条.");
                return;
            }

            // 拟合直线
            cv::Vec4f line;
            cv::fitLine(points, line, cv::DIST_L2, 0, 0.01, 0.01);

            // 计算直线的斜率和坐标
            float vx = line[0];
            float vy = line[1];
            float x0 = line[2];
            float y0 = line[3];
            float slope = vy / vx;
            float intercept = y0 - slope * x0;

            // 计算直线的两个端点
            cv::Point pt1, pt2;
            pt1.x = 0;
            pt1.y = y0 - (x0 * vy / vx);
            pt2.x = frame_.cols - 1;
            pt2.y = y0 + ((frame_.cols - 1 - x0) * vy / vx);

            // 绘制直线
            cv::line(frame_, pt1, pt2, cv::Scalar(0, 0, 255), 2);

            // 显示结果
            cv::namedWindow("Line", cv::WINDOW_NORMAL);
            // 修改窗口大小
            cv::resizeWindow("Line", 800, 600);
            cv::imshow("Line", frame_);
            cv::waitKey(1);

            // 输出直线的斜率和截距
            RCLCPP_INFO(this->get_logger(), "直线斜率: %f, 直线截距: %f", slope, intercept);
            // 发布直线的斜率与截距
            qrmsg::msg::Lf lf_msg;
            lf_msg.lf_k = slope;
            lf_msg.lf_b = intercept;
            lf_publisher_->publish(lf_msg);
        }

        cv::Mat frame_;
        // 声明图像订阅者
        rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr img_subscriber_;
        // 声明斜率与截距发布者
        rclcpp::Publisher<qrmsg::msg::Lf>::SharedPtr lf_publisher_;
};

int main()
{
    rclcpp::init(0, nullptr);
    auto lf = std::make_shared<LineFollow>("line_follow");
    rclcpp::spin(lf);
    rclcpp::shutdown();
    return 0;
}
