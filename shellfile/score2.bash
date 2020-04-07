echo -n 'type your score : '
read score

let grade=$score/10
case $grade in
    "10" | "9") echo A;;
    "8") echo B;;
    "7") echo C;;
    *) echo need more study;;
esac 
