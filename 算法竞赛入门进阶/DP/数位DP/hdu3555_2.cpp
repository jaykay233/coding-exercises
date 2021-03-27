#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[20][2],t[20];
int digit[20];

//state标记前一位是否是4

ll dfs(ll n, int pos,bool state,bool limit){
    if(!pos) return 0;
    if(!limit && ~dp[pos][state]) return dp[pos][state];
    ll res= 0;
    int up = limit ? digit[pos] : 9;
    for(int i=0;i<=up;i++){
        if(state && i==9) res += limit? n % t[pos-1] + 1 : t[pos-1];
        else res += dfs(n,pos-1,i==4,limit && i == digit[pos]); 
    }
    if(!limit) dp[pos][state] = res;
    return res;
}

ll solve(ll n){
    ll m =n;
    int cnt =0 ;
    while(n){
        digit[++cnt]=n%10;
        n/=10;
    }
    return dfs(m,cnt,0,1);
}

int main(){
    memset(dp,-1,sizeof dp);
    t[0]=1;
    for(int i=1;i<=18;i++) t[i] = t[i-1] * 10LL;
    int T;
    scanf("%d",&T);
    while(T--){
        ll n;
        scanf("%lld",&n);
        printf("%lld\n",solve(n));
    }
    return 0;
}