//卡特兰数，逆元
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
#define N 1000000
ll Cata[N+1];

void exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1;y=0;
        return;
    }
    exgcd(b,a%b,x,y);
    ll t = x;
    x = y;
    y = t - a/b * y;
}

void initial(){
    Cata[1] = 1;
    ll x,y;
    for(int i=2;i<=N;i++){
        Cata[i] = (Cata[i-1]*(4*i-2)) % M;
        exgcd(i+1,M,x,y);
        Cata[i] = ((Cata[i-1]*(x%M+M)%M)%M+M)%M;
    }
}

int main(){
    ll n;int T,kase= 0;
    initial();
    scanf("%d",&T);
    while(T--){
        scanf("%lld",&n);
        printf("Case #%d:\n",++kase);
        printf("%lld\n",Cata[n]);
    }
    return 0;
}