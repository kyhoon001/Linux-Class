if [ $# -eq 0 ]
then
	echo how to uss: $0 files
	exit 1
fi

echo "permitted file"
while [ $# -gt 0 ]
do
	file=$1
	if [ -f $file ]
	then
	fileinfo=`ls -l $file`
	perm=`echo "$fileinfo" | cut -d' ' -f1`
	echo "$perm $file"
	fi
	shift
done
