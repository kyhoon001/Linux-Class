if [ $# -eq 0 ]
then
    echo how to use : $0 file*
    exit 1
fi
echo " can use"
for file in $*
do
 if [ -f $file ]
 then
   fileinfo=`ls -l $file`
   perm=`echo "#fileinfo"|cut -d' ' -f1`
   echo "$perm $file"
   fi
done 
