#!/bin/sh
PIN=17
echo $PIN > /sys/class/gpio/export
echo out > /sys/class/gpio/gpio17/direction

while true
do
	echo 1 > /sys/class/gpio/gpio17/value
	sleep 1
	echo 0 > /sys/class/gpio/gpio17/value
	sleep 1
done

#make this pin unavailable through the SysFs
echo $PIN > /sys/class/gpio/unexport
