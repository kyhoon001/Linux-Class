y=1
while [ $y -le 12 ]; do
    x=1
    while [ $x -le 12 ]; do
	printf "% 4d" $(( $x * $y ))
	x=$((x+1))
	done
	echo""
	y=$((y+1))
done
