import cv2
import numpy as np

# 读取图像
image = cv2.imread('/home/jason/gxs/GXS_2024_VisionCode/src/line_follow/images/img_3.jpg')
# 裁减感兴趣区域
height, width, _ = image.shape
start_x = width // 2
start_y = height // 3
end_x = width
end_y = height
image = image[start_y:end_y, start_x:end_x]
# 转换为HSV
hsv_image = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)

# 提取饱和度通道
s_channel = hsv_image[:, :, 1]

# 计算饱和度梯度
sobel_x = cv2.Sobel(s_channel, cv2.CV_64F, 1, 0, ksize=3)
sobel_y = cv2.Sobel(s_channel, cv2.CV_64F, 0, 1, ksize=3)

# 计算梯度幅度
gradient_magnitude = np.sqrt(sobel_x**2 + sobel_y**2)
gradient_magnitude = np.uint8(gradient_magnitude)

# 使用阈值处理提取分界线
_, edges = cv2.threshold(gradient_magnitude, 50, 255, cv2.THRESH_BINARY)

# 在原图上绘制分界线
image_with_edges = image.copy()
image_with_edges[edges == 255] = [0, 0, 255]  # 将边界线标记为红色

# 将图像转换为灰度图，将红色区域留下，其余部分置为黑色
gray_image = cv2.cvtColor(image_with_edges, cv2.COLOR_BGR2GRAY)
_, mask = cv2.threshold(gray_image, 1, 255, cv2.THRESH_BINARY)
image_with_edges = cv2.bitwise_and(image_with_edges, image_with_edges, mask=mask)



# 创建窗口并设置大小
cv2.namedWindow('Original Image', cv2.WINDOW_NORMAL)  # 可调整大小
cv2.namedWindow('Saturation Gradient Magnitude', cv2.WINDOW_NORMAL)
cv2.namedWindow('Edges', cv2.WINDOW_NORMAL)
cv2.namedWindow('Image with Edges', cv2.WINDOW_NORMAL)
cv2.namedWindow('gray', cv2.WINDOW_NORMAL)


cv2.resizeWindow('Image with Edges', 400, 300)  # 设置窗口大小为400x300
cv2.resizeWindow('Saturation Gradient Magnitude', 400, 300)  # 设置窗口大小为400x300
cv2.resizeWindow('Edges', 400, 300)  # 设置窗口大小为400x300
cv2.resizeWindow('Original Image', 400, 300)  # 设置窗口大小为400x300
cv2.resizeWindow('gray', 400, 300)  # 设置窗口大小为400x300
# 显示结果
cv2.imshow('Original Image', image)
cv2.imshow('Saturation Gradient Magnitude', gradient_magnitude)
cv2.imshow('Edges', edges)
cv2.imshow('Image with Edges', image_with_edges)
cv2.imshow('gray', gray_image)
cv2.waitKey(0)
cv2.destroyAllWindows()


