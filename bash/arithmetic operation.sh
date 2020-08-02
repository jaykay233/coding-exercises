read n
sum=0
for (( i=1 ; i<=$n ; i++ ))
do
  read a
  let "sum+=$a"
done
printf "%.3f" $(echo $sum/$n | bc -l)

## second example

sum=0
read n
while read -r line || [[ -n "$line" ]]; do
    sum=$(($sum + $line))
done
printf "%.3f" $(echo "$sum/$n" | bc -l)

