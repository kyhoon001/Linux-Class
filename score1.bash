echo -n "type your score : "
read score

if (( $score >= 90))
then
    echo A

elif (( $score >= 80))
then
    echo B
elif (( $score >= 70))
then
    echo C
else
    echo Need more study
fi

