// Copyright (c) 2022 ChenJun
// Licensed under the Apache-2.0 License.

#ifndef RM_SERIAL_DRIVER__RM_SERIAL_DRIVER_HPP_
#define RM_SERIAL_DRIVER__RM_SERIAL_DRIVER_HPP_
#include <rclcpp/publisher.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/subscription.hpp>
#include <serial_driver/serial_driver.hpp>
#include <std_msgs/msg/float64.hpp>

#include <geometry_msgs/msg/vector3.hpp>
#include <qrmsg/srv/qr.hpp>
#include <std_msgs/msg/bool.hpp>
#include <std_msgs/msg/string.hpp>
// C++ system
#include <future>
#include <memory>
#include <string>
#include <thread>
#include <vector>

namespace rm_serial_driver
{
class RMSerialDriver : public rclcpp::Node
{
public:
  explicit RMSerialDriver(const rclcpp::NodeOptions & options);

  ~RMSerialDriver() override;

private:
  void getParams();

  void receiveData();

  void SendPickData(const geometry_msgs::msg::Vector3::SharedPtr msg);
  void SendQRData(const std_msgs::msg::String::SharedPtr msg);
  void reopenPort();

  void setParam(const rclcpp::Parameter & param);


  // Serial port
  std::unique_ptr<IoContext> owned_ctx_;
  std::string device_name_;
  std::unique_ptr<drivers::serial_driver::SerialPortConfig> device_config_;
  std::unique_ptr<drivers::serial_driver::SerialDriver> serial_driver_;

  // Param client to set detect_colr
  using ResultFuturePtr = std::shared_future<std::vector<rcl_interfaces::msg::SetParametersResult>>;
  bool initial_set_param_ = false;
  uint8_t previous_receive_color_ = 0;
  rclcpp::AsyncParametersClient::SharedPtr detector_param_client_;
  ResultFuturePtr set_param_future_;

  // Service client to reset tracker
  // rclcpp::Client<std_srvs::srv::Trigger>::SharedPtr reset_tracker_client_;

  // Broadcast tf from odom to gimbal_link
  // double timestamp_offset_ = 0;
  // std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;

  // rclcpp::Subscription<auto_aim_interfaces::msg::Target>::SharedPtr target_sub_;
  // rclcpp::Subscription<geometry_msgs::msg::TwistStamped>::SharedPtr cmd_vel_sub_;
  rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr state_pub;
  rclcpp::Subscription<geometry_msgs::msg::Vector3>::SharedPtr colorblock_sub;
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr Qr_sub;
  // For debug usage
  // rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr latency_pub_;
  // rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr marker_pub_;

  // rclcpp::Publisher<decision_moudle::msg::Site>::SharedPtr site_pub;
  // rclcpp::Publisher<decision_moudle::msg::Hp>::SharedPtr health_pub;

  std::thread receive_thread_;


};
}  // namespace rm_serial_driver

#endif  // RM_SERIAL_DRIVER__RM_SERIAL_DRIVER_HPP_
