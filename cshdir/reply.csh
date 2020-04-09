echo -n "Keep going???? "
set reply = $<
if($reply == "yes") then
	echo yes
else if($reply =~ n*) then
	echo No
endif
