# ground-station-pg

Instrukcja odpalenia symulacji

'''bash
cd ros2_sim_ws
colcon build --symlink-install
source install/setup.bash
ros2 launch robot_pkg launch_sim.launch.py
'''

Aby kontrolować ruchy robota w symulacji należy odpalić:
'ros2 run teleop_twist_keyboard teleop_twist_keyboard'

Aby odpalić rviz2 z poglądem na obecny stan robota:
'rviz2 -d /ścieżka/do/robot_sim.rviz'
