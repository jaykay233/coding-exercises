#include <bits/stdc++.h>
using namespace std;
int p;
const int N = 1010;
int a[N],c[N],res[N];

void mul(int a[N],int b[N],int res[N]){
    memset(c,0,sizeof c);
    for(int i =0;i<500;i++){
        for(int j =0;j<500;j++){
            if(i+j<500)
                c[i+j] += a[i]*b[j];
        }
    }
    
    for(int i =0,t =0;i<500;i++){
        t += c[i];
        res[i] = t%10;
        t/=10;
    }
}

int qmi(int p){
    res[0]=1;
    a[0] = 2;
    while(p){
        if(p&1) mul(res,a,res);
        mul(a,a,a);
        p>>=1;
    }
    res[0]-=1;
}

int main(){
    scanf("%d",&p);
    printf("%d\n",int(log10(2)*p)+1);
    qmi(p);
    for(int i = 499;i>=0;){
        for(int k=0;k<50;k++,i--){
            printf("%d",res[i]);
        }
        puts("");
    }
    
    return 0;
}