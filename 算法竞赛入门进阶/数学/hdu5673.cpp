#include <bits/stdc++.h>
using namespace std;
#define MAX 1000010
#define mod 1000000007
typedef long long ll;

ll inv[MAX + 5],C[MAX + 5],cat[MAX + 5];
void init(){
    C[0] = 1;
    inv[1] = 1;
    for(int i=2;i<=MAX;i++)
        inv[i] = (mod - mod/i)*inv[mod%i]%mod;
    cat[0]=cat[1]=1;
    for(int i=2;i<=500000;i++)
        cat[i] = cat[i-1]*(4*i-2)%mod*inv[i+1]%mod;
}

int main(){
    int t;
    init();
    scanf("%d",&t);
    while(t--){
        int n;
        ll ans = 0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            C[i] = C[i-1]*(n-i+1)%mod*inv[i]%mod;
        for(int i=0;i<=n/2;i++)
            ans = (ans + cat[i]*C[i*2])%mod;
        printf("%lld\n",ans);
    }
    return 0;
}