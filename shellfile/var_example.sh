#!/bin/sh
myvar="Hi SSAFY"
echo $myvar
echo "$myvar"
echo '$myvar'
echo \$myvar
echo Enter some text
read myvar
echo '$myvar' now equals $myvar
exit()

