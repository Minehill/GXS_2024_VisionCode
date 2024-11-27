#!/bin/bash

### BEGIN INIT INFO
# Provides:          watchDog
# Required-Start:    $remote_fs $syslog
# Required-Stop:     $remote_fs $syslog
# Default-Start:     2 3 4 5
# Default-Stop:      0 1 6
# Short-Description: start watchDog
# Description:       start watchDog
### END INIT INFO

sec=1
cnt=0
PROC_NAME=component_conta
Thread=`ps -ef | grep ${PROC_NAME} | grep -v "grep"`
sleep $sec
source ~/.bashrc
source /home/lccc/Desktop/GXS_2024_VisionCode/install/setup.bash
ros2 launch colorblock_detector bringup.launch.py 

echo "Thread starting"
