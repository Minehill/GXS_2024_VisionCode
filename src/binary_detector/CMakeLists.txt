cmake_minimum_required(VERSION 3.8)
project(binary_detector)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(OpenCV REQUIRED)
find_package(qrmsg REQUIRED)
find_package(std_msgs REQUIRED)
# find_package(ZBar REQUIRED)

# Use pkg-config to find ZBar
find_package(PkgConfig REQUIRED)
pkg_check_modules(ZBar REQUIRED zbar)

include_directories(
  include
  ${OpenCV_INCLUDE_DIRS}
  ${ZBar_INCLUDE_DIRS}
)

add_library(${PROJECT_NAME} src/binary.cpp)
ament_target_dependencies(${PROJECT_NAME}
  rclcpp
  sensor_msgs
  cv_bridge
  qrmsg
  std_msgs
)

target_link_libraries(${PROJECT_NAME}
  ${OpenCV_LIBRARIES}
  ${ZBar_LIBRARIES}
)

install(TARGETS
  ${PROJECT_NAME}
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY include/
  DESTINATION include/
)

add_executable(binary src/main.cpp)
target_link_libraries(binary
  ${OpenCV_LIBRARIES}
  ${ZBar_LIBRARIES}
  ${PROJECT_NAME}
)

ament_target_dependencies(binary
  rclcpp
  sensor_msgs
  cv_bridge
  qrmsg
  std_msgs
)

install(TARGETS
  binary
  DESTINATION lib/${PROJECT_NAME})


ament_package()
