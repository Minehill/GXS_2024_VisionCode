import rclpy
from rclpy.node import Node
from rcl_interfaces.msg import ParameterType
from rcl_interfaces.msg import ParameterDescriptor
import cv2
import numpy as np
import math

class LineFollower(Node):
    def __init__(self):
        super().__init__('line_follow')
        self.declare_parameters(
            namespace='',
            parameters=[
                ('lower_white', [90, 0, 0]),  # 白色的HSV下限
                ('upper_white', [180, 150, 255]),  # 白色的HSV上限
                ('lower_yellow', [0, 40, 0]),  # 黄色的HSV下限
                ('upper_yellow', [255, 100, 255]),  # 黄色的HSV上限
                ('min_line_length', 50),
                ('max_line_gap', 60),
                ('if_debug', True)
            ]
        )
        # self.cap = cv2.VideoCapture(0)
        # if not self.cap.isOpened():
        #     self.get_logger().error("无法打开摄像头")
        #     rclpy.shutdown()

    def pro_img(self):
        # ret, img = self.cap.read()

        img = cv2.imread('src/line_follow/images/img_6.jpg')
        # 展示原图，但是修改展示大小(通过创建窗口、resize、imshow)


        lower_white = np.array(self.get_parameter('lower_white').get_parameter_value().integer_array_value, dtype=np.uint8)
        upper_white = np.array(self.get_parameter('upper_white').get_parameter_value().integer_array_value, dtype=np.uint8)
        lower_yellow = np.array(self.get_parameter('lower_yellow').get_parameter_value().integer_array_value, dtype=np.uint8)
        upper_yellow = np.array(self.get_parameter('upper_yellow').get_parameter_value().integer_array_value, dtype=np.uint8)
        min_line_length = self.get_parameter('min_line_length').get_parameter_value().integer_value
        max_line_gap = self.get_parameter('max_line_gap').get_parameter_value().integer_value
        if_debug = self.get_parameter('if_debug').get_parameter_value().bool_value

        if if_debug:
            cv2.namedWindow('ori', cv2.WINDOW_NORMAL)
            cv2.resizeWindow('ori', 752, 423)
            cv2.imshow('ori', img)

        HSV = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
        # 增强饱和度（使颜色更接近于纯色）
        HSV[..., 1] = np.clip(HSV[..., 1] * 1.5 , 0, 255)
        img = cv2.cvtColor(HSV, cv2.COLOR_HSV2BGR)
        img = self.cat(img)

        mask_white = cv2.inRange(img, lower_white, upper_white)
        mask_yellow = cv2.inRange(img, lower_yellow, upper_yellow)
        # mask = cv2.bitwise_or(mask_white, mask_yellow)
    
        result = cv2.bitwise_and(img, img, mask=mask_yellow)

        if if_debug:
            cv2.imshow('kk', result)

        gray = cv2.cvtColor(result, cv2.COLOR_RGB2GRAY)
        ret, binary = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY | cv2.THRESH_OTSU)
        kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (3, 3))
        # 膨胀
        # for i in range(10):
        #     eroded = cv2.dilate(binary, kernel)
        #     binary = eroded
        # 腐蚀
        for i in range(5):
            eroded = cv2.erode(binary, kernel)
            binary = eroded
        # 使用高斯概率加权求和，对边缘做平滑化处理
        gauss = cv2.GaussianBlur(binary, (3, 3), 0)
        # 检测边缘
        edges = cv2.Canny(gauss, 50, 100)

        mask = np.zeros_like(edges)
        if len(edges.shape) > 2:
            channel_count = edges.shape[2]
            ignore_mask_color = (255,) * channel_count
        else:
            ignore_mask_color = 255
        # 定义感兴趣区域
        vertices =  np.array([[(0, edges.shape[0]), (0*edges.shape[1] / 20, 6*edges.shape[0] / 20), (20* edges.shape[1]/20, 6 * edges.shape[0]/20), (edges.shape[1], edges.shape[0])]], dtype=np.int32)
        # 在感兴趣区域中，使用ignore_mask_color（白色）填充mask（全黑色）,最终，感兴趣区域均为白色，其余区域为黑色
        cv2.fillPoly(mask, vertices, ignore_mask_color)
        # 获取感兴趣区域下的边缘（白色255），其余均置为黑色0
        masked_image = cv2.bitwise_and(edges, mask)
        """
        masked_image: 输入的二值图像，通常是边缘检测后的图像。
        1: 距离分辨率，霍夫变换中距离的单位（像素）。
        np.pi/180: 角度分辨率，霍夫变换中角度的单位（弧度）。
        25: 阈值，只有累加器中的值高于该阈值时才被认为是一条直线。
        np.array([]): 占位符，表示没有初始线条。
        minLineLength: 最小线段长度，线段短于此长度的将被忽略。
        maxLineGap: 最大线段间隙，线段之间的间隙大于此值的将被视为两条独立的线段。
        """
        lines = cv2.HoughLinesP(masked_image, 1, np.pi/180, 25, np.array([]), minLineLength=min_line_length, maxLineGap=max_line_gap)
        line_image = np.zeros_like(edges)
        
        try:
            flage_r = self.draw_lines(line_image, lines, thickness=10)
        except:
            flage_r = None
        
        line_image = cv2.addWeighted(edges, 0.8, line_image, 1, 0)
        # 在原图img可视化找到的线
        # 确保line_image的尺寸和通道数与img匹配
        line_image = cv2.resize(line_image, (img.shape[1], img.shape[0]))
        if len(line_image.shape) == 2:
            line_image_ = cv2.cvtColor(line_image, cv2.COLOR_GRAY2BGR)
        # 将找到的线可视化到原图上
        res_ = cv2.addWeighted(img, 0.8, line_image_, 1, 0)
        cv2.imshow("img", img)
        cv2.imshow("result", result)
        cv2.imshow("binary", binary)
        cv2.imshow("find_line", line_image)
        cv2.imshow("res", res_)
        while True:
            if cv2.waitKey(1) & 0xFF == ord('q'):
                break

    def cat(self, image):
        image = cv2.resize(image, (752, 423))
        height, width, _ = image.shape
        # 只处理右侧部分
        start_x = width // 2
        start_y = height // 3
        end_x = width
        end_y = height
        cropped_image = image[start_y:end_y, start_x:end_x]
        return cropped_image

    def draw_lines(self, image, lines, color=[255,0,0], thickness=2):
        """
        image: 输入的图像
        lines: 由HoughLinesP函数得到的直线集合
        color: 线段颜色
        thickness: 线段粗细
        """
        right_y_set = []
        right_x_set = []
        right_slope_set = []

        # 斜率绝对值范围
        slope_min = .25
        slope_max = 2.95
        middle_x = image.shape[1] / 2
        max_y = image.shape[0]
        
        flage_r = None

        if lines is None:
            return
        for line in lines:
            # 每个line是一个包含两个点的数组，每个点是一个包含两个坐标的数组
            for x1, y1, x2, y2 in line:
                # debug: 每条线的长度和对应的斜率
                # length = math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)
                # print('length:', length)

                # 拟合成直线，返回斜率（fit[0]）和截距(fit[1])
                fit = np.polyfit((x1, x2), (y1, y2), 1)
                slope = fit[0]

                # print('slope: ', slope, 'length: ', length)

                if slope > 0 and slope_min < np.absolute(slope) <= slope_max:
                    right_y_set.append(y1)
                    right_y_set.append(y2)
                    right_x_set.append(x1)
                    right_x_set.append(x2)
                    right_slope_set.append(slope)

                    # elif slope < 0:
                    #     left_y_set.append(y1)
                    #     left_y_set.append(y2)
                    #     left_x_set.append(x1)
                    #     left_x_set.append(x2)
                    #     left_slope_set.append(slope)

        try:
            if right_y_set:
                lindex = right_y_set.index(min(right_y_set))
                right_x_top = right_x_set[lindex]
                right_y_top = right_y_set[lindex]
                rslope = np.median(right_slope_set)

            right_x_bottom = int(right_x_top + (max_y - right_y_top) / rslope)
            if if_debug:
                cv2.line(image, (right_x_bottom, max_y), (right_x_top, right_y_top), color, thickness)
            print('rslope:', rslope)
            angle_rad = math.atan2((max_y - right_y_top), (right_x_bottom-right_x_top))
            angle_deg = int(math.degrees(angle_rad))
            flage_r = angle_deg
        except:
            pass
        print('flage_r:', flage_r)
        return flage_r

def main(args=None):
    rclpy.init(args=args)
    node = LineFollower()
    # while rclpy.ok():
    #     node.pro_img()
    #     rclpy.spin_once(node)
    node.pro_img()

    # node.cap.release()
    cv2.destroyAllWindows()
    rclpy.shutdown()

if __name__ == '__main__':
    main()