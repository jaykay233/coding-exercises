#include <bits/stdc++.h>
using namespace std;
const int N=10000010;
typedef long long ll;
const ll MOD=1000000007;
typedef double db;
typedef unsigned int uint;
typedef unsigned long long ull;
int f[N];
int find_f(int a) {
    return f[a]==a?a:f[a]=find_f(f[a]);
}
int unio(int a,int b) {
    int fa=find_f(a),fb=find_f(b);
    if (fa!=fb) { f[fa]=fb;return 1; }
    else return 0;
}
ll qpow(ll a,ll b) {
    ll ret=1;
    while (b) {
        if (b&1) (ret*=a)%=MOD;
        (a*=a)%=MOD;b>>=1;
    }
    return ret;
}
int main()
{
    int i,n,m,l,r,g;
    while (scanf("%d%d", &n, &m)!=EOF) {
        for (i=1;i<=n+1;i++) f[i]=i;
        for (g=n,i=1;i<=m;i++) {
            scanf("%d%d", &l, &r);
            g-=unio(l,r+1);
        }
        printf("%lld\n", qpow(26,g));
    }
    return 0;
}