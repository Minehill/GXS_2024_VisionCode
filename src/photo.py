import cv2

# 打开USB摄像头
cap = cv2.VideoCapture(0)

if not cap.isOpened():
    print("无法打开摄像头")
    exit()

# 初始化图像计数器
image_counter = 1

print("按 'c' 键拍照，按 'q' 键退出程序。")

try:
    while True:
        # 读取摄像头画面
        ret, frame = cap.read()
        if not ret:
            print("无法从摄像头读取画面")
            break

        # 显示画面
        
	# 创建一个可调整大小的窗口
        cv2.namedWindow('Camera', cv2.WINDOW_NORMAL)

	# 调整窗口大小
        cv2.resizeWindow('Camera', 400, 300)  # 设定窗口大小为800x600像素

        cv2.imshow('Camera', frame)
        
        cv2.waitKey(1)

finally:
    # 释放摄像头并关闭所有窗口
    cap.release()
    cv2.destroyAllWindows()

