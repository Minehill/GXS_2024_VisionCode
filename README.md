# GXS_2024_VisionCode
源码架构：
|- src  
|-- adjust  
|-- line_follow
|-- binary_detector  
|-- colorblock_detector  
|-- qrmsg  
|-- image_data  
|--- photo.py  
|--- images  
|-- 其余编译文件  
|- readme.md  


其中，adjust用于动态调参，line_follow用于巡线， binary_detector用于识别二维码，colorblock_detector用于检测目标物料,qrmsg为消息文件。二维码识别和物料识别之间采用服务形式进行通信。photo.py用于拍摄数据，储存在images中。
# 启动
./gxs_startup.bash
# 高优先级启动
sudo chrt -f 99 ./gxs_startup.bash 
# 持续发布false
while true; do ros2 topic pub /if_done std_msgs/Bool "{data: false}" --once; sleep 0.5; done
# 发布一次true
ros2 topic pub /if_done std_msgs/Bool "{data: true}" --once

* v2.0.1 : 色环搜索变过程中，使用新的扩张方法：在n*n的区域内，若存在白色像素点，则中心点置为白色
* v2.0.2 : 新增巡线，发送截距与斜率
