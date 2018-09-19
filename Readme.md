# Experiment to isolate the tf bug.

Issue is described here: https://github.com/ros/geometry/issues/176

## Reproduce

Build with docker:

```sh
docker build --network=host -f docker/Dockerfile -t test179 .
```
Run:

Start roscore:

```sh
nohup roscore &
#then start the docker
docker run --env-file ./docker/ros.env --cap-add=SYS_PTRACE --security-opt seccomp=unconfined -it --network=host -t test179 bash
```
Note, the cap-add options are needed to use GDB to see the stacktrace.

Debugging with dgb inside docker image:

```sh
cd /root/catkin_ws
gdb ./develop/lib/test179/test179
run
#after it crashes
bt
```

The output of the gdb stack trace is:
```
Thread 1 "test179" received signal SIGSEGV, Segmentation fault.
0x00007ffff73bddda in ros::TimeBase<ros::Time, ros::Duration>::operator+(ros::Duration const&) const () from /opt/ros/kinetic/lib/librostime.so
(gdb) bt
#0  0x00007ffff73bddda in ros::TimeBase<ros::Time, ros::Duration>::operator+(ros::Duration const&) const () from /opt/ros/kinetic/lib/librostime.so
#1  0x00007ffff65d6013 in tf2_ros::Buffer::canTransform(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, ros::Time const&, ros::Duration, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >*) const () from /opt/ros/kinetic/lib/libtf2_ros.so
#2  0x00007ffff7bb6a3f in tf::Transformer::waitForTransform(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, ros::Time const&, ros::Duration const&, ros::Duration const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >*) const ()
   from /opt/ros/kinetic/lib/libtf.so
#3  0x000000000040a8ac in main (argc=1, argv=0x7fffffffe448) at /root/catkin_ws/src/test179/src/test_bug179.cpp:31
```
