# GXS_2024_VisionCode
源码架构：
|- src  
|-- adjust  
|-- binary_detector  
|-- colorblock_detector 
|-- qrmsg  
|-- image_data  
|--- photo.py  
|--- images  
|-- 其余编译文件  
|- readme.md  


其中，adjust用于动态调参，binary_detector用于识别二维码，colorblock_detector用于检测目标物料,qrmsg为消息文件。二维码识别和物料识别之间采用服务形式进行通信。photo.py用于拍摄数据，储存在images中。
# 启动
ros2 launch colorblock_detector bringup.launch.py
