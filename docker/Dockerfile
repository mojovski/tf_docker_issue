### Dockerfile for ROS on edge
FROM ros:kinetic

# install all packages
RUN apt-get update  && apt-get install -y build-essential \
		       git \
		       ros-kinetic-xacro \ 
		       ros-kinetic-dwa-local-planner \
		       ros-kinetic-robot-state-publisher \
		       ros-kinetic-turtlebot3-description \
		       ros-kinetic-turtlebot3-simulations \
		       ros-kinetic-cv-bridge \
		       ros-kinetic-interactive-markers \
		       keychain \
		       python-pip \
		       ros-kinetic-costmap-prohibition-layer \
		       nano \
		       psmisc \
		       htop \
		       iproute2 \
		       libsdl-dev \
		       libsdl-image1.2-dev \
		       libyaml-cpp-dev \
		       ros-kinetic-geometry2 \
		       ros-kinetic-bfl \
		       ros-kinetic-move-base-msgs \
		       ros-kinetic-std-msgs \
		       gdb
		       


# ros env variables
ENV CATKIN_WS /root/catkin_ws
ENV ROS_ROOT=/opt/ros/kinetic/share/ros
ENV ROS_PACKAGE_PATH=/root/catkin_ws/src:/opt/ros/kinetic/share:/opt/ros/kinetic/stacks
ENV PATH=/root/catkin_ws/devel/bin:/opt/ros/kinetic/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
# ENV ROSLISP_PACKAGE_DIRECTORIES=/root/catkin_ws/devel/share/common-lisp
ENV ROS_DISTRO=kinetic
ENV PYTHONPATH=/root/catkin_ws/devel/lib/python2.7/dist-packages:/opt/ros/kinetic/lib/python2.7/dist-packages
ENV PKG_CONFIG_PATH=/root/catkin_ws/devel/lib/pkgconfig:/root/catkin_ws/devel/lib/x86_64-linux-gnu/pkgconfig:/opt/ros/kinetic/lib/x86_64-linux-gnu/pkgconfig:/opt/ros/kinetic/lib/pkgconfig
ENV CMAKE_PREFIX_PATH=/root/catkin_ws/devel:/opt/ros/kinetic

RUN apt-get install -y ros-kinetic-turtlesim
 
# add required commands to bashrc
RUN echo "source /opt/ros/kinetic/setup.bash" >> /root/.bashrc
RUN echo "source /root/catkin_ws/devel/setup.bash" >> /root/.bashrc


# create workspace and install all packages globally
RUN mkdir -p $CATKIN_WS/src
WORKDIR $CATKIN_WS/src
ADD [ "./cpp", "$CATKIN_WS/src/test179" ]
RUN ls $CATKIN_WS/src

WORKDIR $CATKIN_WS

RUN catkin_make install --cmake-args -DCMAKE_INSTALL_PREFIX=/opt/ros/kinetic/ -DCMAKE_BUILD_TYPE=Debug
RUN chmod +x /root/catkin_ws/devel/setup.bash && \
    bash -c "source /root/catkin_ws/devel/setup.bash"


CMD /opt/ros/kinetic/lib/test179/test179
