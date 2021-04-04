#include <bits/stdc++.h>
using namespace std;
const long long mod = 200907;

long long pow_mod(long long x,long long a,long long n){
    long long base = x;
    long long res = 1;
    while(a){
        if(a&1) res *= base % n;
        res %= n;
        base *= base;
        base %= n;
        a>>=1;
    }
    return res % n;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long long a1,a2,a3;
        long long k;
        scanf("%lld%lld%lld%lld",&a1,&a2,&a3,&k);

        if(a2-a1==a3-a2){
            long long d = (a2-a1)%mod;
            long long temp = ((a1%mod) + ((d%mod)*((k-1)%mod)))%mod;
            printf("%lld\n",temp);
        }
        else{
            long long p = a2/a1;
            long long temp = ((a1%mod)*(pow_mod(p,k-1,mod)))%mod;
            printf("%lld\n",temp);
        }
    }
    return 0;
}