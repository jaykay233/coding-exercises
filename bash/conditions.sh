read x
if [[ $x == "N" || $x == "n" ]]
then
    echo "NO"
else 
    echo "YES"    
fi


##字符串相等用 == 或者 =
##数字相等用 -eq
read a
read b
read c
if [[ a -eq b && b -eq c && a -eq c ]]
then
    echo "EQUILATERAL"
elif [[ a -eq b ||  b -eq c || c -eq a  ]]
then
    echo "ISOSCELES"
else
    echo "SCALENE"
fi