#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <image_transport/image_transport.hpp>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>

class ImagePublisher : public rclcpp::Node {
public:
    ImagePublisher() : Node("image_publisher") {
        // 创建图像发布者
        publisher_ = this->create_publisher<sensor_msgs::msg::Image>("image_topic", 10);
        // 打开 USB 摄像头
        cap_.open(0); // 0 为默认摄像头
        if (!cap_.isOpened()) {
            RCLCPP_ERROR(this->get_logger(), "Failed to open camera");
            return;
        }

        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(30), std::bind(&ImagePublisher::publish_image, this));
    }

private:
    void publish_image() {
        cv::Mat frame;
        cap_ >> frame; // 捕获图像

        if (!frame.empty()) {
            // 将 OpenCV 图像转换为 ROS 图像消息
            auto ros_image = cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", frame).toImageMsg();
            publisher_->publish(*
            ros_image);
        }
    }

    cv::VideoCapture cap_;
    // 定义图像发布者
    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr publisher_;

    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ImagePublisher>());
    rclcpp::shutdown();
    return 0;
}

