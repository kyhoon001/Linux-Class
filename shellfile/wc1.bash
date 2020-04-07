if [ $# -ne 1 ]
then
	echo how to use: $0 file
	exit 1
fi
file=$1
wc $file

