if($#argv != 1) then
	echo how to use : $0 file
	exit 1
endif
set file = $argv[1]
wc $file

