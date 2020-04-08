BEGIN {
print "Starting to process INPUT"
}
{
 a += $5; t++
}
END {
 print "count of files",t, "total size: ",a
}
