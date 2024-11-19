#include "binary_detector/binary.hpp"

#include <opencv2/opencv.hpp>
#include <zbar.h>
#include <string>
#include <vector>
#include <qrmsg/srv/qr.hpp>
#include <qrmsg/msg/qr.hpp>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float64.hpp>
#include <std_msgs/msg/bool.hpp>
#include <std_msgs/msg/string.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <cv_bridge/cv_bridge.h>
using namespace cv;
using namespace zbar;
using namespace std;


QrDetector::QrDetector() : Node("binary_detect") 
{
    RCLCPP_INFO(this->get_logger(), "binary detect 启动");
    res_ = "none";
    // 是否找到二维码
    if_find = false;
    // 图像订阅者
    img_subscriber_ = this->create_subscription<sensor_msgs::msg::Image>(
        "image_topic", 10,
        std::bind(&QrDetector::image_callback, this, std::placeholders::_1));
        RCLCPP_INFO(this->get_logger(), "binary detect 启动结束");
    // 二维码信息发布者
    qr_pub = this->create_publisher<std_msgs::msg::String>("qr_msg", 10);
}

// 订阅图像的回调函数
void QrDetector::image_callback(const sensor_msgs::msg::Image::SharedPtr msg) {
    // 将 ROS 图像消息转换为 OpenCV 图像
    cv_bridge::CvImagePtr cv_ptr = cv_bridge::toCvCopy(msg, "bgr8");
    frame_ = cv_ptr->image;
    
    res_ = detect(frame_);
}

// 以下代码为识别二维码
pair<string, int> QrDetector::decodeDisplay(const Mat& image) 
{
    // 初始化zbar扫描器
    ImageScanner scanner;
    scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);

    // 将OpenCV的Mat转换为zbar的Image
    Mat gray;
    cvtColor(image, gray, COLOR_BGR2GRAY);
    Image zbarImage(gray.cols, gray.rows, "Y800", gray.data, gray.cols * gray.rows);

    // 扫描二维码
    int n = scanner.scan(zbarImage);
    if (n == 0) {
        return make_pair("none", 0);
    } else {
        // 提取二维码数据
        for (Image::SymbolIterator symbol = zbarImage.symbol_begin(); symbol != zbarImage.symbol_end(); ++symbol) {
            string barcodeData = symbol->get_data();
            // 将该消息发布(发布前转换为ROS2的标准消息)
            auto message = std_msgs::msg::String();
            message.data = barcodeData;
            qr_pub->publish(message);

            return make_pair(barcodeData, 1);
        }
    }
    return make_pair("none", 0);
}

string QrDetector::detect(const Mat& image) 
{
    string result = "";
    if (!if_find)
    {
        if (image.empty())
        {
            RCLCPP_INFO(this->get_logger(), "no image");
            return "none";
        } 

        pair<string, int> rt = decodeDisplay(image);
        
        if (rt.second)
        {
            result = rt.first;
            if_find = true;
            return result;
        }
        else
            return "none";
    }
}

QrRequest::QrRequest(std::string name, int arr_[6]) : Node(name) 
{   
    RCLCPP_INFO(this->get_logger(), "节点已启动：%s.", name.c_str());
    if_done = false;
    int i = 0;
    while(i < 6)
    {
        arr[i] = arr_[i];
        i++;
    }
    now_index = 0;

    state_sub = this->create_subscription<std_msgs::msg::Bool>(
        "/if_done", 10,
        std::bind(&QrRequest::send_request, this, std::placeholders::_1)
    );

    request_publisher = this->create_publisher<qrmsg::msg::Qr>("/request", 10);

    // timer_ = this->create_wall_timer(
    //     std::chrono::milliseconds(10),
    //     std::bind(&QrRequest::send_request, this)
    // );



}

// void QrRequest::state_callback(const std_msgs::msg::Bool::SharedPtr msg)
// {
//     if (msg->data)
//     {
//         RCLCPP_INFO(this->get_logger(), "callback receive, %d", msg->data);
//         if_done = msg->data;
//         now_index++;
//         return;
//     }
//     else
//         if_done = 0;
// }

void QrRequest::send_request(const std_msgs::msg::Bool::SharedPtr msg) 
{
    // RCLCPP_INFO(this->get_logger(), "pick for %d, using way %d", arr[now_index], now_index/3);

    // 圆盘色块，色环，色环上的色块，色环
    int way_arr[4] = {0, 1, 2, 1};

    auto message = qrmsg::msg::Qr();
    message.num = arr[now_index % 3];
    int i_ = now_index / 3;
    message.way = way_arr[i_];
    // if ((now_index/3) % 2)
    //     message.way = 1;
    // else
    //     message.way = 0;
    // message.way = now_index / 3;
    message.is_new = false;

    if (msg->data)
    {
        RCLCPP_INFO(this->get_logger(), "done it");
        now_index++;
        message.is_new = true;
    }
    if (now_index > 11)
    {
        RCLCPP_INFO(this->get_logger(), "任务完成");
        return;
    }
    // RCLCPP_INFO(this->get_logger(), "if_done? %d", if_done);
    RCLCPP_INFO(this->get_logger(), "now_index: %d, now_num: %d", now_index, message.num);
    request_publisher->publish(message);

}
// void QrRequest::send_request(int &num_, int &way_) 
// {
//     RCLCPP_INFO(this->get_logger(), "pick for %d, using way %d", num_, way_);

//     // 1.等待服务端上线
//     while (!client_->wait_for_service(std::chrono::seconds(1))) 
//     {
//         //等待时检测rclcpp的状态
//         if (!rclcpp::ok()) 
//         {
//         RCLCPP_ERROR(this->get_logger(), "等待服务的过程中被打断...");
//         return;
//         }
//         RCLCPP_INFO(this->get_logger(), "等待服务端上线中");
//     }

//     // 2.构造请求
//     auto request = std::make_shared<qrmsg::srv::Qr::Request>();
//     request->num = num_;
//     request->way = way_;
//     request->is_new = true;

//     // 3.发送异步请求，然后等待返回，返回时调用回调函数
//     client_->async_send_request(
//         request, std::bind(&QrRequest::result_callback_, this,
//                             std::placeholders::_1));
// }

// // 此时已经找到了目标，只需要继续前进即可
// void QrRequest::again_send_request(int &num_, int &way_) 
// {   
//     // 2.构造请求
//     auto request = std::make_shared<qrmsg::srv::Qr::Request>();
//     request->num = num_;
//     request->way = way_;
//     request->is_new = true;

//     // 3.发送同步请求，然后等待返回，返回时调用回调函数
//     // auto result_future = client_->async_send_request(request);
//     client_->async_send_request(
//         request, std::bind(&QrRequest::again_result_callback_, this,
//                             std::placeholders::_1));
// }


// void QrRequest::again_result_callback_(rclcpp::Client<qrmsg::srv::Qr>::SharedFuture result_future) 
// {
//    RCLCPP_INFO(this->get_logger(), "you return ");
//    response = result_future.get();
// }


// void QrRequest::result_callback_(rclcpp::Client<qrmsg::srv::Qr>::SharedFuture result_future) 
// {
//     response = result_future.get();
//     // 若完成，则发布距离消息
//     if (response->finish)
//     {
//     	dis = response->dis;
//    	/*	
//         // 继续调用服务，当距离小于一定值时停止。
//         while (response->finish && response->dis > 0)
//         {
//             RCLCPP_INFO(this->get_logger(), "当前距离为 %f, 继续前进", response->dis);
//             int _way_ = now_index / 3;
//             response->finish = false;
//             again_send_request(arr[now_index], _way_);
//             while(!response->finish)
//             {
            	
//             }
//         }
//         now_index++;
//         */
//     }
//     else
//         RCLCPP_INFO(this->get_logger(), "第 %d 次行动失败, 此时捡取编号为 %d", now_index+1, arr[now_index]);
    
//     /*
//     if (now_index > 5)
//     {
//         RCLCPP_INFO(this->get_logger(), "任务完成");
//         return;
//     }
//     int way_ = now_index / 3;
//     send_request(arr[now_index], way_);
//     */

// }
