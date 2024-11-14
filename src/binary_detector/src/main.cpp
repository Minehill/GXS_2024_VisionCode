#include "binary_detector/binary.hpp"

#include <opencv2/opencv.hpp>
#include <zbar.h>
#include <string>
#include <vector>
#include <qrmsg/srv/qr.hpp>
#include <thread>
#include <rclcpp/rclcpp.hpp>

using namespace cv;
using namespace zbar;
using namespace std;
int main(int argc, char** argv) 
{
    rclcpp::init(argc, argv);

    auto Qd = std::make_shared<QrDetector>();

    while (Qd->res_ == "none")
    {
        rclcpp::spin_some(Qd); 
    }

    string result = Qd->res_;
    int i = 0, j = 0;
    int arr_[6];

    while(result[i])
    {
        std::cout << result[i] << endl;
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
