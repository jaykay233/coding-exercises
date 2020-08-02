//质数连向合数
//二分图
#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 1e5+10;
int cnt =0;
int primes[N];
bool st[N];

void init(int n){
    for(int i =2;i<=n;i++){
        if(!st[i]) primes[cnt++]  =i;
        for(int j=0;primes[j]*i<=n;j++){
            st[primes[j]*i] = true;
            if(i%primes[j]==0)
                break;
        }
    }
}

int main(){
    scanf("%d",&n);
    init(N);
    if(n<3) puts("1");
    else puts("2");
    int pcnt;
    for(int i=2,pcnt = 0;pcnt<n;i++,pcnt++){
        if(!st[i]) printf("%d ",1);
        else printf("%d ",2);
    }
    printf("\n");

    return 0;
}