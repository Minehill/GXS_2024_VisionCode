#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat image; // 全局变量，原始图像

// 滑块回调函数
void on_trackbar(int, void*) {
    // 获取 HSV 色域的范围
    int h_min = getTrackbarPos("H min", "Filtered Image");
    int h_max = getTrackbarPos("H max", "Filtered Image");
    int s_min = getTrackbarPos("S min", "Filtered Image");
    int s_max = getTrackbarPos("S max", "Filtered Image");
    int v_min = getTrackbarPos("V min", "Filtered Image");
    int v_max = getTrackbarPos("V max", "Filtered Image");

    // 将原图像从 BGR 转换到 HSV
    Mat hsv_image;
    cvtColor(image, hsv_image, COLOR_BGR2HSV);

    // 创建阈值范围
    Scalar lower(h_min, s_min, v_min);
    Scalar upper(h_max, s_max, v_max);

    // 根据 HSV 色域过滤图像
    Mat mask;
    inRange(hsv_image, lower, upper, mask);

    // 应用掩码到原图像
    Mat result;
    bitwise_and(image, image, result, mask);
    // 显示过滤后的图像
    imshow("Filtered Image", result);
}

int main(int argc, char** argv) {
    string path = "/home/lccc/Desktop/GXS_2024_VisionCode/src/image_data/images/3.png"; 

    // 加载图像
    image = imread(path);
    if (image.empty()) {
        cout << "Error loading image" << endl;
        return -1;
    }

    // 创建一个可调整大小的窗口
    cv::namedWindow("Filtered Image", cv::WINDOW_NORMAL);

    // 调整窗口大小
    cv::resizeWindow("Filtered Image", 300, 200);

    // 初始化滑块值
    int h_min = 0, h_max = 180;
    int s_min = 0, s_max = 255;
    int v_min = 0, v_max = 255;

    // 创建滑块，并将滑块值指针设置为 NULL，确保使用回调来获取滑块值
    createTrackbar("H min", "Filtered Image", NULL, 180, on_trackbar);
    createTrackbar("H max", "Filtered Image", NULL, 180, on_trackbar);
    createTrackbar("S min", "Filtered Image", NULL, 255, on_trackbar);
    createTrackbar("S max", "Filtered Image", NULL, 255, on_trackbar);
    createTrackbar("V min", "Filtered Image", NULL, 255, on_trackbar);
    createTrackbar("V max", "Filtered Image", NULL, 255, on_trackbar);

    // 手动触发一次回调，以初始化显示
    on_trackbar(0, 0);

    // 等待按键按下
    waitKey(0);

    return 0;
}
