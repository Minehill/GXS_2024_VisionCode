cmake_minimum_required(VERSION 3.5)
project(line_follow)

# 找到必要的包
find_package(ament_cmake REQUIRED)
find_package(rclpy REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(OpenCV REQUIRED)

# 安装Python脚本
install(
  DIRECTORY src/
  DESTINATION lib/${PROJECT_NAME}
  FILES_MATCHING PATTERN "*.py"
)

# 安装launch文件
install(
  DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME}/launch
)

# 生成Python可执行文件
ament_python_install_package(${PROJECT_NAME})

# 生成launch文件
ament_package()