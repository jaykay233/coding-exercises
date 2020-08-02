#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int primes[N];
bool st[N];
int cnt = 0;

void init(int n){
    for(int i=2;i<=n;i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j =0;primes[j]*i<=n;j++){
            st[i*primes[j]] = true;
            if(i % primes[j]==0) break;
        } 
    }
}

int  main(){
    int n;
    init(N);
    while(scanf("%d",&n) && n){
        int res =-1;
        int a1,a2;
        for(int i =0;i<cnt && primes[i]<n;i++){
            int b = n - primes[i];
            if(!st[b]){
                if(b - primes[i]>res){
                    res  = b - primes[i];
                    a1 = primes[i],a2 = b;
                    break;
                }
            }
        }
        printf("%d = %d + %d\n",n,a1,a2);
    }

    return 0;
}