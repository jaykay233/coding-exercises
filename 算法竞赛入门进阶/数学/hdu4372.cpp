//第一类Stirling数
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2005;
const ll MOD = 1e9+7;

ll C[N][N];
ll S[N][N];

void init(){
    int i,j;
    for(i=0;i<N;i++){
        C[i][0] = 1;
        C[i][i] = 1;
        S[i][0] = 0;
        S[i][i] = 1;
        for(j=1;j<i;j++){
            C[i][j] = (C[i-1][j]%MOD + C[i-1][j-1]%MOD)%MOD;
            S[i][j] = ((i-1)%MOD*S[i-1][j]%MOD + S[i-1][j-1]%MOD);
        }
    }
}

int main(){
    ll t,n,f,b,ans;
    init();
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld%lld",&n,&f,&b);
        ans = C[f+b-2][f-1]%MOD*S[n-1][f+b-2]%MOD;
        printf("%lld\n",ans);
    }

    return 0;
}