FROM ros:humble-ros-base

# Add ubuntu user with same UID and GID as your host system, if it doesn't already exist
# Since Ubuntu 24.04, a non-root user is created by default with the name vscode and UID=1000
ARG USERNAME=ubuntu
ARG USER_UID=1000
ARG USER_GID=$USER_UID
RUN if ! id -u $USER_UID >/dev/null 2>&1; then \
        groupadd --gid $USER_GID $USERNAME && \
        useradd -s /bin/bash --uid $USER_UID --gid $USER_GID -m $USERNAME; \
    fi
# Add sudo support for the non-root user
RUN apt-get update && \
    apt-get install -y sudo && \
    echo "$USERNAME ALL=(root) NOPASSWD:ALL" > /etc/sudoers.d/$USERNAME && \
    chmod 0440 /etc/sudoers.d/$USERNAME

# Switch from root to user
USER $USERNAME

# Add user to video group to allow access to webcam
RUN sudo usermod --append --groups video $USERNAME

# Update all packages
RUN sudo apt update && sudo apt upgrade -y

# Install Git
RUN sudo apt install -y git

# Rosdep update
RUN rosdep update

# Source the ROS setup file
RUN echo "source /opt/ros/${ROS_DISTRO}/setup.bash" >> ~/.bashrc

################################
## ADD ANY CUSTOM SETUP BELOW ##
################################

# Install rosdep
RUN sudo apt update && sudo apt install -y python3-rosdep

# Install ROS2 Humble Nav2, Nav2 bringup, and Cartographer
RUN sudo apt update && sudo apt install -y \
    ros-humble-navigation2 \
    ros-humble-nav2-bringup \
    ros-humble-cartographer \
    ros-humble-cartographer-ros \
    ros-humble-slam-toolbox -y

# Installing gazebo fortress
RUN sudo apt-get update && \
    sudo apt-get install lsb-release gnupg
RUN sudo curl https://packages.osrfoundation.org/gazebo.gpg --output /usr/share/keyrings/pkgs-osrf-archive-keyring.gpg
RUN echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/pkgs-osrf-archive-keyring.gpg] http://packages.osrfoundation.org/gazebo/ubuntu-stable $(lsb_release -cs) main" | sudo tee /etc/apt/sources.list.d/gazebo-stable.list > /dev/null
RUN sudo apt-get update 
RUN sudo apt-get install -y ignition-fortress

# Installing rviz
RUN sudo apt install ros-humble-rviz2

# Installing packages to help with urtf file creationg
RUN sudo apt install ros-humble-xacro ros-humble-joint-state-publisher-gui -y
RUN sudo apt install ros-humble-rqt-graph -y
RUN sudo apt install ros-humble-gazebo-ros-pkgs -y
RUN sudo apt update -y
RUN sudo apt install ros-humble-teleop-twist-keyboard -y

# Installing packages for robot controll
RUN sudo apt install ros-humble-ros2-control -y
RUN sudo apt install ros-humble-ros2-controllers -y
RUN sudo apt install ros-humble-gazebo-ros2-control -y
RUN sudo apt install joystick jstest-gtk evtest -y
RUN sudo apt install ros-humble-joy -y
RUN sudo apt install python3-tk -y