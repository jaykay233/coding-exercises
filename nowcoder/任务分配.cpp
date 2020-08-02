#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
const int N = 200010;
int n,m;
LL S;
int w[N],v[N];
int l[N],r[N];
int cnt[N];
LL sum[N];

LL get(int W){
    for(int i=1;i<=n;i++){
        if(w[i]>=W){
            sum[i] = sum[i-1] + v[i];
            cnt[i] = cnt[i-1] + 1;
        }else{
            sum[i] = sum[i-1];
            cnt[i] = cnt[i-1];
        }
    }
    LL res=0;
    for(int i =0;i<m;i++) res+=(cnt[r[i]]-cnt[l[i]-1])*(sum[r[i]]-sum[l[i]-1]);
    return res;
}

int main(){
    scanf("%d%d%lld",&n,&m,&S);
    for(int i=1;i<=n;i++) scanf("%d%d",&w[i],&v[i]);
    for(int i=0;i<m;i++) scanf("%d%d",&l[i],&r[i]);
    int l = 0, r= 1e6+1;
    while(l<r){
        int mid = l + r + 1>>1;
        if(get(mid)>=S) l = mid;
        else r = mid-1;
    }
    printf("%lld\n",min(abs(get(r)-S),abs(S-get(r+1))));

    return 0;
}