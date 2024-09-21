# from PIL import Image
# import cv2
# import numpy as np
# import math
# import os

# def cat(image):
#     image = cv2.resize(image, (752, 423))
#     height, width, _ = image.shape
#     # 计算裁剪区域的起始点和大小
#     start_x = 0
#     start_y = height // 3
#     end_x = width
#     end_y = height # 前三分之一的高度
#     # 裁剪图像
#     cropped_image = image[start_y:end_y, start_x:end_x]
#     return cropped_image

# def draw_lines(image, lines, color=[255,0,0], thickness=2):

#     right_y_set = []
#     right_x_set = []
#     right_slope_set = [] # 这个是用来存储斜率的

#     left_y_set = []
#     left_x_set = []
#     left_slope_set = []

#     slope_min = .25  # 斜率低阈值
#     slope_max = 2.95  # 斜率高阈值
#     middle_x = image.shape[1] / 2  # 图像中线x坐标
#     max_y = image.shape[0]  # 最大y坐标
    
#     flage_l = None
#     flage_r = None

#     if lines is None:
#         return
#     for line in lines:
#         for x1, y1, x2, y2 in line:
#             fit = np.polyfit((x1, x2), (y1, y2), 1)    # 拟合成直线
#             slope = fit[0]  # 斜率

#             if slope_min < np.absolute(slope) <= slope_max:

#                 # 将斜率大于0且线段X坐标在图像中线右边的点存为右边车道线
#                 # if slope > 0 and x1 > middle_x and x2 > middle_x:
#                 if slope > 0 :
                    
#                     right_y_set.append(y1)
#                     right_y_set.append(y2)
#                     right_x_set.append(x1)
#                     right_x_set.append(x2)
#                     right_slope_set.append(slope)

#                 # 将斜率小于0且线段X坐标在图像中线左边的点存为左边车道线
#                 elif slope < 0 :
#                     left_y_set.append(y1)
#                     left_y_set.append(y2)
#                     left_x_set.append(x1)
#                     left_x_set.append(x2)
#                     left_slope_set.append(slope)

#     try:
#         # 绘制左车道线
#         if left_y_set:
#             lindex = left_y_set.index(min(left_y_set))  # 最高点
#             left_x_top = left_x_set[lindex]
#             left_y_top = left_y_set[lindex]
#             lslope = np.median(left_slope_set)   # 计算平均值

#         # 根据斜率计算车道线与图片下方交点作为起点
#         left_x_bottom = int(left_x_top + (max_y - left_y_top) / lslope)

#         # 绘制线段
#         cv2.line(image, (left_x_bottom, max_y), (left_x_top, left_y_top), color, thickness)
#         angle_rad = math.atan2((max_y - left_y_top), (left_x_bottom-left_x_top))
#         angle_deg = int(math.degrees(angle_rad))
#         flage_l = angle_deg

#         # 绘制右车道线
#         if right_y_set:
#             lindex = right_y_set.index(min(right_y_set))  # 最高点
#             right_x_top = right_x_set[lindex]
#             right_y_top = right_y_set[lindex]
#             rslope = np.median(right_slope_set)   # 计算平均值

#         # 根据斜率计算车道线与图片下方交点作为起点
#         right_x_bottom = int(right_x_top + (max_y - right_y_top) / rslope)

#         # 绘制线段
#         cv2.line(image, (right_x_bottom, max_y), (right_x_top, right_y_top), color, thickness)
#         angle_rad = math.atan2((max_y - right_y_top), (right_x_bottom-right_x_top))
#         angle_deg = int(math.degrees(angle_rad))
#         flage_r = angle_deg
#     except:
#         pass
    
#     return flage_l
# def pro_img(img):
#     # 读取图片。
#     # img = cv2.imread(path);
#     HSV = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
#     HSV[..., 1] = np.clip(HSV[..., 1] * 1.5 , 0, 255)
#     img = cv2.cvtColor(HSV, cv2.COLOR_HSV2BGR)
#     img = cat(img)
#     # print(path)
#     # 读取图像
#     # cv2.imshow("dfsd", img)
#     # cv2.waitKey(0)
#     # 定义颜色范围
#     # 下限：RGB(20, 150, 50)
#     # 上限：RGB(30, 255, 120)
#     lower_white = np.array([15, 130, 130], dtype=np.uint8)
#     upper_white = np.array([100, 190, 190], dtype=np.uint8)

#     # 提取被阈值选中的部分
#     mask = cv2.inRange(img, lower_white, upper_white)
#     frame = cv2.bitwise_and(img, img, mask=mask)

#     # 将掩码应用到图像上，将指定颜色区域变为白色，其他区域变为黑色
#     result = cv2.bitwise_and(img, img, mask=mask)
#     cv2.imshow("mask", result)
#     cv2.waitKey(1)
#     # 转换为灰度图进行处理
#     gray = cv2.cvtColor(result, cv2.COLOR_RGB2GRAY)
#     ret, binary = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY | cv2.THRESH_OTSU)
#     # cv2.imshow("gray", binary)
#     # cv2.waitKey(1)
#     # 使用腐蚀膨胀操作，去除噪声
#     kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (3, 3))
#     for i in range(10):
#         eroded = cv2.dilate(binary, kernel)
#         binary = eroded
#     # cv2.imshow("pz", binary)
#     # cv2.waitKey(1)
#     for i in range(3):
#         eroded = cv2.erode(binary, kernel)
#         binary = eroded
#     # cv2.imshow("fs", binary)
#     # cv2.waitKey(1)
#     # 使用高斯滤波，去除噪声，提取边缘
#     gauss = cv2.GaussianBlur(binary, (3, 3), 0)
#     # cv2.imshow("sd", gauss)
#     # cv2.waitKey(1)
#     edges = cv2.Canny(gauss, 50, 100)

#     mask = np.zeros_like(edges)

#     if len(edges.shape) > 2:
#         channel_count = edges.shape[2]
#         ignore_mask_color = (255,) * channel_count
#     else:
#         ignore_mask_color = 255

#     # 定义感兴趣区域
#     vertices =  np.array([[(0, edges.shape[0]), (0*edges.shape[1] / 20, 6*edges.shape[0] / 20), (20* edges.shape[1]/20, 6 * edges.shape[0]/20), (edges.shape[1], edges.shape[0])]], dtype=np.int32)
#     cv2.fillPoly(mask, vertices, ignore_mask_color)
#     masked_image = cv2.bitwise_and(edges, mask)

#     # 使用霍夫变换检测直线
#     lines = cv2.HoughLinesP(masked_image, 1, np.pi/180, 25, np.array([]), minLineLength=30, maxLineGap=60)
#     line_image = np.zeros_like(edges)

#     try:
#         flage_l= draw_lines(line_image, lines, thickness=10)
#     except:
#         flage_l,flage_r = None,None
#     line_image = cv2.addWeighted(edges, 0.8, line_image, 1, 0)
#     cv2.imshow("1", line_image)
#     cv2.waitKey(0)

# if __name__ == '__main__':
#     # image_path = r'C:\Users\19848\Desktop\linedata\5.jpg'
#     # img = cv2.imread(image_path)
#     # 开启摄像头
#     cap = cv2.VideoCapture(0)
#     while True:
#         ret, img = cap.read()
#         pro_img(img)

#     # print(1)
#     # pro_img(img)
#     # print(2)


import rclpy
from rclpy.node import Node
from rcl_interfaces.msg import ParameterType
from rcl_interfaces.msg import ParameterDescriptor
import cv2
import numpy as np
import math

class LineFollower(Node):
    def __init__(self):
        super().__init__('line_follower')
        self.declare_parameters(
            namespace='',
            parameters=[
                ('lower_white', [15, 130, 130]),
                ('upper_white', [100, 190, 190]),
                ('min_line_length', 30),
                ('max_line_gap', 60),
                ('if_debug', False)
            ]
        )
        self.cap = cv2.VideoCapture(0)
        if not self.cap.isOpened():
            self.get_logger().error("无法打开摄像头")
            rclpy.shutdown()

    def pro_img(self, img):
        lower_white = np.array(self.get_parameter('lower_white').get_parameter_value().integer_array_value, dtype=np.uint8)
        upper_white = np.array(self.get_parameter('upper_white').get_parameter_value().integer_array_value, dtype=np.uint8)
        min_line_length = self.get_parameter('min_line_length').get_parameter_value().integer_value
        max_line_gap = self.get_parameter('max_line_gap').get_parameter_value().integer_value
        if_debug = self.get_parameter('if_debug').get_parameter_value().bool_value

        HSV = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
        HSV[..., 1] = np.clip(HSV[..., 1] * 1.5 , 0, 255)
        img = cv2.cvtColor(HSV, cv2.COLOR_HSV2BGR)
        img = self.cat(img)

        mask = cv2.inRange(img, lower_white, upper_white)
        frame = cv2.bitwise_and(img, img, mask=mask)
        result = cv2.bitwise_and(img, img, mask=mask)
        gray = cv2.cvtColor(result, cv2.COLOR_RGB2GRAY)
        ret, binary = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY | cv2.THRESH_OTSU)
        kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (3, 3))
        for i in range(10):
            eroded = cv2.dilate(binary, kernel)
            binary = eroded
        for i in range(3):
            eroded = cv2.erode(binary, kernel)
            binary = eroded
        gauss = cv2.GaussianBlur(binary, (3, 3), 0)
        edges = cv2.Canny(gauss, 50, 100)

        mask = np.zeros_like(edges)
        if len(edges.shape) > 2:
            channel_count = edges.shape[2]
            ignore_mask_color = (255,) * channel_count
        else:
            ignore_mask_color = 255

        vertices =  np.array([[(0, edges.shape[0]), (0*edges.shape[1] / 20, 6*edges.shape[0] / 20), (20* edges.shape[1]/20, 6 * edges.shape[0]/20), (edges.shape[1], edges.shape[0])]], dtype=np.int32)
        cv2.fillPoly(mask, vertices, ignore_mask_color)
        masked_image = cv2.bitwise_and(edges, mask)

        lines = cv2.HoughLinesP(masked_image, 1, np.pi/180, 25, np.array([]), minLineLength=min_line_length, maxLineGap=max_line_gap)
        line_image = np.zeros_like(edges)

        try:
            flage_l = self.draw_lines(line_image, lines, thickness=10)
        except:
            flage_l, flage_r = None, None
        line_image = cv2.addWeighted(edges, 0.8, line_image, 1, 0)
        cv2.imshow("1", line_image)
        cv2.waitKey(1)

    def cat(self, image):
        image = cv2.resize(image, (752, 423))
        height, width, _ = image.shape
        start_x = 0
        start_y = height // 3
        end_x = width
        end_y = height
        cropped_image = image[start_y:end_y, start_x:end_x]
        return cropped_image

    def draw_lines(self, image, lines, color=[255,0,0], thickness=2):
        right_y_set = []
        right_x_set = []
        right_slope_set = []

        left_y_set = []
        left_x_set = []
        left_slope_set = []

        slope_min = .25
        slope_max = 2.95
        middle_x = image.shape[1] / 2
        max_y = image.shape[0]
        
        flage_l = None
        flage_r = None

        if lines is None:
            return
        for line in lines:
            for x1, y1, x2, y2 in line:
                fit = np.polyfit((x1, x2), (y1, y2), 1)
                slope = fit[0]

                if slope_min < np.absolute(slope) <= slope_max:
                    if slope > 0:
                        right_y_set.append(y1)
                        right_y_set.append(y2)
                        right_x_set.append(x1)
                        right_x_set.append(x2)
                        right_slope_set.append(slope)
                    elif slope < 0:
                        left_y_set.append(y1)
                        left_y_set.append(y2)
                        left_x_set.append(x1)
                        left_x_set.append(x2)
                        left_slope_set.append(slope)

        try:
            if left_y_set:
                lindex = left_y_set.index(min(left_y_set))
                left_x_top = left_x_set[lindex]
                left_y_top = left_y_set[lindex]
                lslope = np.median(left_slope_set)

            left_x_bottom = int(left_x_top + (max_y - left_y_top) / lslope)
            cv2.line(image, (left_x_bottom, max_y), (left_x_top, left_y_top), color, thickness)
            angle_rad = math.atan2((max_y - left_y_top), (left_x_bottom-left_x_top))
            angle_deg = int(math.degrees(angle_rad))
            flage_l = angle_deg

            if right_y_set:
                lindex = right_y_set.index(min(right_y_set))
                right_x_top = right_x_set[lindex]
                right_y_top = right_y_set[lindex]
                rslope = np.median(right_slope_set)

            right_x_bottom = int(right_x_top + (max_y - right_y_top) / rslope)
            cv2.line(image, (right_x_bottom, max_y), (right_x_top, right_y_top), color, thickness)
            angle_rad = math.atan2((max_y - right_y_top), (right_x_bottom-right_x_top))
            angle_deg = int(math.degrees(angle_rad))
            flage_r = angle_deg
        except:
            pass
        
        return flage_l

def main(args=None):
    rclpy.init(args=args)
    node = LineFollower()
    while rclpy.ok():
        ret, img = node.cap.read()
        if ret:
            node.pro_img(img)
        rclpy.spin_once(node)
    node.cap.release()
    cv2.destroyAllWindows()
    rclpy.shutdown()

if __name__ == '__main__':
    main()