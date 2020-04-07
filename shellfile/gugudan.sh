for i in `seq 9`
do
	for j in `seq 2 9`
	do
	res=$((i*j))
	printf "$j X $i = $res\t"
	done
	echo
done
