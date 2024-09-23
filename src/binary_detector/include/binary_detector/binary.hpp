# ifndef BINARY_DETECTOR__BINARY_HPP_

# define BINARY_DETECTOR__BINARY_HPP_
#include <opencv2/opencv.hpp>
#include <zbar.h>
#include <string>
#include <vector>
#include <qrmsg/srv/qr.hpp>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float64.hpp>
using namespace cv;
using namespace zbar;
using namespace std;

class QrDetector
{
    public:
        QrDetector();

        // 以下代码为识别二维码
        pair<string, int> decodeDisplay(const Mat& image);
        string detect(const Mat& frame);
        bool if_find;

};

class QrRequest : public rclcpp::Node 
{
public:

  QrRequest(std::string name, int arr_[6]);

  void send_request(int &num_, int &way_);

  // 真实距离发布者
  rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr distance_publisher;
  // 距离阈值，当距离小于该值时，停止发布
  double distance_threshold = 0.05;

private:
  void result_callback_(rclcpp::Client<qrmsg::srv::Qr>::SharedFuture result_future);
  rclcpp::Client<qrmsg::srv::Qr>::SharedPtr client_;
  int now_index, arr[6];
};

#endif