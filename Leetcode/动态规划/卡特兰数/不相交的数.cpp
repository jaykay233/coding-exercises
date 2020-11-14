#include <bits/stdc++.h>
using namespace std;
//不相交的数
class Solution {
public:
    typedef long long LL;
    int numberOfWays(int n) {
        n /=2;
        int p=1e9+7;
        return (Lucas(2*n,n,p)-Lucas(2*n,n-1,p)+p)%p;
    }

    LL pow(LL a,LL b,LL p){
        LL res = 1;
        while(b){
            if(b&1) res *= a%p;
            res%=p;
            b>>=1;
            a = (a*a)%p;
        }
        return res;
    }

    LL com(LL n, LL m, LL p){
        LL a=1, b=1;
        if(m > n) return 0;
        while(m){
            a=(a*n--)%p;
            b=(b*m--)%p;
        }
        return a*pow(b,p-2,p)%p;
    }

    LL Lucas(LL n,LL m,LL p){
        if(m==0) return 1;
        return com(n%p,m%p,p)*Lucas(n/p,m/p,p);
    }
};