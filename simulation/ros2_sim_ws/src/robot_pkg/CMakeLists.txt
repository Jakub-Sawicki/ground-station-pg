cmake_minimum_required(VERSION 3.8)
project(robot_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)

add_executable(uart_publisher src/uart_publisher.cpp)
ament_target_dependencies(uart_publisher rclcpp geometry_msgs)

install(TARGETS uart_publisher DESTINATION lib/${PROJECT_NAME})

install(
  DIRECTORY launch description config
  DESTINATION share/${PROJECT_NAME}
  OPTIONAL
)

ament_package()
