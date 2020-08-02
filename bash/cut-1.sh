while read line
do
    echo $line | cut -c 3
done

while read line 
do
    echo $line | cut -c 2,7
done

cut -f -3