#include <stdarg.h>
#include <stdio.h>

int sum(int, ...);

int main(){
    printf("10, 20 and 30 sum = %d\n", sum(3,10,20,30));
    printf("4, 20, 25 and 30 sum = %d\n", sum(4,4,20,25,30));
    return 0;
}

int sum(int num_args, ...){
    int val = 0;
    va_list ap;
    int i;
    va_start(ap, num_args);
    for(int i =0;i<num_args;i++){
        val += va_arg(ap, int);
    }
    va_end(ap);

    return val;
}