#include <bits/stdc++.h>
using namespace std;
int T;
const int N = 5e5+10;
typedef long long LL;
LL s[N];
LL x[N];
LL odds[N];
LL sums[N];

int main(){
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        int n,o,d;
        scanf("%d %d %d",&n,&o,&d);
        LL a,b,c,m,l;
        scanf("%lld %lld %lld %lld %lld %lld %lld",&x[1],&x[2],&a,&b,&c,&m,&l);
        for(int i =1;i<=n;i++){
            if(i>=3) x[i] = (a*x[i-1] + b*x[i-2] + c) % m;
            s[i] = x[i] + l;
        }
        for(int i=1;i<=n;i++){
            if(s[i]%2) odds[i] = odds[i-1] + 1;
            else odds[i] = odds[i-1];
        }

        for(int i=1;i<=n;i++){
            sums[i] = sums[i-1] + s[i];
        }

        multiset<LL> ordered_sum;
        int left = 1;
        int cnt =0;
        long long ans = -1e9;
        for(int i = 1;i<=n;i++){
            while(left<i && odds[i] - odds[left] >= o){
                ordered_sum.erase(sums[left]);
                left++;
            }
            auto it = ordered_sum.lower_bound(sums[i]-d);
            if(it!=ordered_sum.end()){
                ans = max(ans,sums[i] - *it);
            }
            ordered_sum.insert(sums[i]);
        }
        cout<<ans<<endl;
    }

    return 0;
}