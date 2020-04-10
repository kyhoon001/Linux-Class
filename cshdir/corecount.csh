#!/bin/csh
set fileinfo = `cat /proc/cpuinfo |grep "cpu cores"`
echo $fileinfo
