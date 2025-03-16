import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/simulation/ros2_sim_ws/install/joystick_tester'
