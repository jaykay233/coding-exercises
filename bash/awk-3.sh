## 0是整行的意思
awk '{avg=($2+$3+$4)/3; print $0, ":", (avg<50)?"FAIL":(avg<80)?"B":"A"}'

## 打成两行
awk '{
    if ( NR%2==1 )
        printf "%s;",$0
    else
        printf "%s\n",$0
}'

