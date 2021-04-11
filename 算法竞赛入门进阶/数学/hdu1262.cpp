#include <stdio.h>
 
int a[10005];
 
int main(){
	int M,i,j;
	
	for(i = 1; i <10000; i ++){
		int flag = 0;
		
		for(j = 2; j <= i / 2; j ++){
			if(i % j == 0){
				flag = 1;
				break;
			}
		}
		
		if(flag == 0)
			a[i] = 1;
	}
	
	while(scanf("%d",&M)!=EOF){
		
		for(i = M/2;i > 0; i --){	
			if(a[i] == 1 && a[M - i] == 1){
				printf("%d %d\n",i,M-i);
				break;
			}
		}
	}
	
	return 0;
}
