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
int main(int argc, char** argv) 
{
    rclcpp::init(argc, argv);
    // 示例代码：从摄像头读取帧并检测二维码
    // VideoCapture cap(0);
    // if (!cap.isOpened()) {
    //     return -1;
    // }

    // Mat frame;
    // while (cap.read(frame)) {
    //     string result = detect(frame);
    //     if (result != "none") {
    //         cout << "Detected QR Code: " << result << endl;
    //     }
    //     imshow("Frame", frame);
    //     if (waitKey(30) >= 0) break;
    // }

    Mat frame = cv::imread("/home/jason/gxs/GXS_2024_VisionCode/src/binary_detector/image.png");
    auto Qd = std::make_shared<QrDetector>();
    string result = Qd->detect(frame);
    int i = 0, j = 0;
    int arr_[6];

    while(result[i])
    {
        if (result[i] == '+')
        {
            i++;
            continue;
        }
        arr_[j++] = int(result[i++]-'0');
    }
    
    auto node =  std::make_shared<QrRequest>("QrRequest", arr_);
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
