//sg打表函数
#include <bits/stdc++.h>
using namespace std;
int sg[110],k;
int find(int i){
    if(sg[i]!=-1) return sg[i];
    int use[100],j;
    memset(use,0,sizeof use);
    for(int j=1;j<=i;j*=k)
        use[find(i-j)]=1;
    j = 0;
    while(use[j]) j++;
    return sg[i] = j;
}

//找规律

int main(){
    int i,t,T,k,s;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        scanf("%d%d",&s,&k);
        if(k&1){
            if(s&1) printf("1\n");
            else printf("0\n");
        }
        else{
            int tem = s%(k+1);
            if(tem==k) printf("%d\n",k);
            else{
                if(tem&1) printf("1\n");
                else printf("0\n");
            }
        }
    }
    return 0;
}