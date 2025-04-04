set(_AMENT_PACKAGE_NAME "robot_pkg")
set(robot_pkg_VERSION "0.0.0")
set(robot_pkg_MAINTAINER "ubuntu <kuba_sawicki@onet.pl>")
set(robot_pkg_BUILD_DEPENDS "rclpy" "geometry_msgs" "python3-serial")
set(robot_pkg_BUILDTOOL_DEPENDS "ament_cmake")
set(robot_pkg_BUILD_EXPORT_DEPENDS "rclpy" "geometry_msgs" "python3-serial")
set(robot_pkg_BUILDTOOL_EXPORT_DEPENDS )
set(robot_pkg_EXEC_DEPENDS "demo_nodes_cpp" "demo_nodes_py" "rclpy" "geometry_msgs" "python3-serial")
set(robot_pkg_TEST_DEPENDS "ament_lint_auto" "ament_lint_common")
set(robot_pkg_GROUP_DEPENDS )
set(robot_pkg_MEMBER_OF_GROUPS )
set(robot_pkg_DEPRECATED "")
set(robot_pkg_EXPORT_TAGS)
list(APPEND robot_pkg_EXPORT_TAGS "<build_type>ament_cmake</build_type>")
