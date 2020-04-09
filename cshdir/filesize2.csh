#!/bin/csh

if ($#argv == 0) then
        echo how to use: $0 files*
        exit 1
endif

echo "file name, size(bites)"

while ( $#argv )
        set file = $argv[1]
        if (-f $file) then
         set fileinfo = `ls -l $file`
         set size = $fileinfo[5]
         echo "$file $size"
         endif
        shift
end

