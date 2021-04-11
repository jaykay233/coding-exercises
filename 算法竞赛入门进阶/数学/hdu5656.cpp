//gcd+dp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}

const int N = 1003;
const int mod = 1e8+7;
ll dp[N][N], g[N][N];

int main(){
    for(int i=0;i<=1000;i++){
        for(int j =0;j<=1000;j++){
            g[i][j] = gcd(i,j);
        }
    }

    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;++cas){
        int n;
        memset(dp,0,sizeof dp);
        scanf("%d",&n);
        dp[0][0]=1;
        for(int i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            for(int j=0;j<=1000;j++){
                int t = g[j][x];
                dp[i+1][t] += dp[i][j];
                dp[i+1][j] += dp[i][j];
                dp[i+1][t] %= mod;
                dp[i+1][j] %= mod;
            }
        }
        
        ll ans =0 ;
        for(int j=1;j<=1000;j++) ans += dp[n][j] * j;
        printf("%lld\n",ans%mod);
    }
    return 0;
}