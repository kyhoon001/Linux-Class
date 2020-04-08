BEGIN { a = 1 }
$5 > 4096 { a++ }
END {print"cnt :  ",a }

