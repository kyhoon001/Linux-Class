#!/bin/csh
if ($#argv == 0) then
	set dir = "."
else
	set dir = $argv[1]
endif
if( ! -d $dir) then
	echo $0\: $dir is not directory
	exit 1
endif

@ fcount = 0
@ dcount = 0
@ others = 0
echo $dir\:
cd $dir
foreach file (*)
	if( -f $file) then
		@ fcount++
	else if ( -d $file) then
		@ dcount +=1
	else
		@ others++
	endif
end
echo file : $fcount directory : $dcount others : $others
