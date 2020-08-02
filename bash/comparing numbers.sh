##注意事项:
##[]的左括号右侧和右括号左侧都必须留出一个空格
read a
read b
if [ $a -lt $b ]
then
    echo "X is less than Y"  
elif [ $a -eq $b ]
then
    echo "X is equal to Y"   
elif [ $a -gt $b ]
then
    echo "X is greater than Y"  
fi

