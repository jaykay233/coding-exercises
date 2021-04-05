#include <stdio.h>  
  
int main()  
{  
    int t, i, j;  
    long long n, b, a=9973;  
  
    scanf("%d", &t);  
    for(i=0; i<t; i++) {  
        scanf("%lld%lld", &n, &b);  
        for(j=0; j<a; j++)  
            if((j * b - n) % a == 0) {  
                printf("%d\n", j);  
                break;  
            }  
    }  
  
    return 0;  
} 
