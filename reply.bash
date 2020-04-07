echo -n "keep going? "
read reply
if [ $reply == "yes" ]
then
    echo "yes"
elif [ $reply == "no" ]
then
    echo "nope"
fi
