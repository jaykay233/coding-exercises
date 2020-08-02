## my answer
X = 1
while [ $X -le 100]
do
    echo $X
    X = $((X+2))
done

## other answers
for number in {1..99..2}
do 
    echo $number
done