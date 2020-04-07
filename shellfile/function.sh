yes_or_no() {
echo "Is Your Name $1?"
while true
	do
	    echo -n "Enter Yes or no: "
	    read X
	    case "$X" in
	        y|Y|yes|Yes|YES) return 0;;
		n|N|no|No|NO) return 1;;
		*) echo "Answer yes or no"
	    esac
	done
}
echo "Original parameters are $*"
if yes_or_no "$1"
then
    echo "Hi $1"
else
    echo "Oh! Sorry"
fi
exit 0;

