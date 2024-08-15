import cv2
import keyboard

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
        cv2.imshow('Camera', frame)

        # 检测键盘输入
        if keyboard.is_pressed('c'):
            # 保存图像
            img_name = f"{image_counter}.png"
            cv2.imwrite(img_name, frame)
            print(f"拍照成功，图片保存为 {img_name}")
            image_counter += 1

        elif keyboard.is_pressed('q'):
            # 按下 'q' 键退出
            print("退出程序")
            break

        # 延迟1毫秒，以使循环不会占用过多CPU资源
        cv2.waitKey(1)

finally:
    # 释放摄像头并关闭所有窗口
    cap.release()
    cv2.destroyAllWindows()
