//https://blog.csdn.net/qq_41286356/article/details/89975170
#include <bits/stdc++.h>
using namespace std;
int n;
typedef long long ll;
ll phi(ll n){
    ll ans = n;
    for(ll i=2;i<=sqrt(n);i++){
        if(n%i==0){
            ans = ans /i*(i-1);
            while(n%i==0) n/=i;
        }
    }
    if(n>1) ans = ans /n*(n-1);
    return ans;
}


int main(){
    int t;
    cin>>t;
    ll n,m;
    while(t--){
        scanf("%lld%lld",&n,&m);
        ll ans = 0;
        for(ll i=1;i*i<=n;i++){
            if(n%i==0){
                if(i>=m) ans += phi(n/i);
                if(i*i!=n && n/i>=m) ans+=phi(i);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}