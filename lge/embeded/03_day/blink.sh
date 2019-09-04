#!/bin/bash
echo 16 > /sys/class/gpio/export
echo out > /sys/class/gpio/gpio16/direction
for  i in  1 2 3 4 5      
do
	echo 1 > /sys/class/gpio/gpio16/value
	sleep 1
	echo 0 > /sys/class/gpio/gpio16/value
	sleep 1
done
echo 16 > /sys/class/gpio/unexport
