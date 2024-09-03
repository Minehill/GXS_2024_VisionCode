#include "binary_detector/binary.hpp"

#include <opencv2/opencv.hpp>
#include <zbar.h>
#include <string>
#include <vector>
#include <qrmsg/srv/qr.hpp>
#include <rclcpp/rclcpp.hpp>

using namespace cv;
using namespace zbar;
using namespace std;


QrDetector::QrDetector()
{
    // 是否找到二维码
    if_find = false;
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
            return make_pair(barcodeData, 1);
        }
    }
    return make_pair("none", 0);
}

string QrDetector::detect(const Mat& frame) 
{
    string result = "";
    while (!if_find)
    {
        pair<string, int> rt = decodeDisplay(frame);
        
        if (rt.second)
        {
            result = rt.first;
            if_find = true;
        }
    }

    return result;
}


QrRequest::QrRequest(std::string name, int arr_[6]) : Node(name) 
{
RCLCPP_INFO(this->get_logger(), "节点已启动：%s.", name.c_str());
int i = 0;
while(i < 6)
{
    arr[i] = arr_[i];
    i++;
}

client_ = this->create_client<qrmsg::srv::Qr>("QrCallSearch");

now_index = 0;
int way_ = now_index / 3;
send_request(arr[now_index], way_);
}

void QrRequest::send_request(int &num_, int &way_) 
{
RCLCPP_INFO(this->get_logger(), "pick for %d, using way %d", num_, way_);

// 1.等待服务端上线
while (!client_->wait_for_service(std::chrono::seconds(1))) 
{
    //等待时检测rclcpp的状态
    if (!rclcpp::ok()) 
    {
    RCLCPP_ERROR(this->get_logger(), "等待服务的过程中被打断...");
    return;
    }
    RCLCPP_INFO(this->get_logger(), "等待服务端上线中");
}

// 2.构造请求
auto request = std::make_shared<qrmsg::srv::Qr::Request>();
request->num = num_;
request->way = way_;

// 3.发送异步请求，然后等待返回，返回时调用回调函数
client_->async_send_request(
    request, std::bind(&QrRequest::result_callback_, this,
                        std::placeholders::_1));
}

void QrRequest::result_callback_(rclcpp::Client<qrmsg::srv::Qr>::SharedFuture result_future) 
{
    auto response = result_future.get();
    if (response->finish)
        now_index++;
    else
        RCLCPP_INFO(this->get_logger(), "第 %d 次行动失败, 此时捡取编号为 %d", now_index+1, arr[now_index]);
    if (now_index > 5)
    {
        RCLCPP_INFO(this->get_logger(), "任务完成");
        return;
    }
    int way_ = now_index / 3;
    send_request(arr[now_index], way_);
}
