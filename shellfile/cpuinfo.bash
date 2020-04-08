echo `cat /proc/cpuinfo | grep "cpu cores"`
echo `cat /proc/cpuinfo | grep "cpu cores" | cut -d ' ' -f 3`
