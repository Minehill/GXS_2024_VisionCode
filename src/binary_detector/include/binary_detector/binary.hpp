# ifndef BINARY_DETECTOR__BINARY_HPP_

# define BINARY_DETECTOR__BINARY_HPP_
#include <opencv2/opencv.hpp>
#include <zbar.h>
#include <string>
#include <vector>
#include <qrmsg/srv/qr.hpp>
#include <qrmsg/msg/qr.hpp>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float64.hpp>
#include <std_msgs/msg/bool.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <cv_bridge/cv_bridge.h>
using namespace cv;
using namespace zbar;
using namespace std;

class QrDetector : public rclcpp::Node 
{
    public:
        QrDetector();

        // 以下代码为识别二维码
        pair<string, int> decodeDisplay(const Mat& image);
        string detect(const Mat& image);
        bool if_find;
        string res_;
        // 图像
        cv::Mat frame_;
        // 图像订阅者
        rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr img_subscriber_;
        // 图像回调函数
        void image_callback(const sensor_msgs::msg::Image::SharedPtr msg);

};

class QrRequest : public rclcpp::Node 
{
public:

  QrRequest(std::string name, int arr_[6]);

  // void send_request(int &num_, int &way_); 
  // void again_send_request(int &num_, int &way_);
  
  // 是否完成当前动作
  rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr state_sub;

  // 真实距离发布者
  rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr distance_publisher;

  // 当前状态发布者
  rclcpp::Publisher<qrmsg::msg::Qr>::SharedPtr request_publisher;

  // 定时器
  rclcpp::TimerBase::SharedPtr timer_;

  // 距离阈值，当距离小于该值时，停止发布
  double distance_threshold = 0.05;
  double dis;


private:
  // void result_callback_(rclcpp::Client<qrmsg::srv::Qr>::SharedFuture result_future);
  // void again_result_callback_(rclcpp::Client<qrmsg::srv::Qr>::SharedFuture result_future);
  // void state_callback(const std_msgs::msg::Bool::SharedPtr msg);
  void send_request(const std_msgs::msg::Bool::SharedPtr msg);
  
  // rclcpp::Client<qrmsg::srv::Qr>::SharedPtr client_;
  int now_index, arr[6];
  bool is_new;
  bool if_done;
  // std::shared_ptr<qrmsg::srv::Qr::Response> response;
};

#endif
