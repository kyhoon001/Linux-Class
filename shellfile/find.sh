if [ $# -eq 0 ]
then
	echo enter the file name.
	exit 1
fi
echo `whereis $1 | cut -d ' ' -f 2`
# if you want to get the size of $1, type this code
# ex : whereis bash | wc -w 
