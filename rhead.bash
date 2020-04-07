cd $1
for file in *
do
    if [ -f $file ]
    then
    echo "=====================$file==================="
    head $file
    fi

if [ -d $file ]
then
   ~/rhead.bash $file
fi
done
