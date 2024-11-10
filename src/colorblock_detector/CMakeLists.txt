cmake_minimum_required(VERSION 3.8)
project(colorblock_detector)


# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(OpenCV REQUIRED)
find_package(qrmsg REQUIRED)
find_package(geometry_msgs REQUIRED)

include_directories(
  include
  ${OpenCV_INCLUDE_DIRS}
)

add_executable(colorblock src/colorblock.cpp)
target_link_libraries(colorblock
  ${OpenCV_LIBRARIES}
)

ament_target_dependencies(colorblock
  rclcpp
  cv_bridge
  qrmsg
  geometry_msgs
)

install(
  DIRECTORY config/
  DESTINATION share/${PROJECT_NAME}/config
)

install(DIRECTORY launch
DESTINATION share/${PROJECT_NAME})

install(TARGETS
  colorblock
  DESTINATION lib/${PROJECT_NAME})

ament_package()
