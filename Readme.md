# Experiment to isolate the tf bug.


##Reproduce

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
gdb ./develop/llib/test179/test179
run
#after it crashes
bt
```
