#include <bits/stdc++.h>
using namespace std;
int T;
int n;
const int N = 110;
int s[N],e[N],l[N];

struct stone{
    int s,e,l;
    bool operator<(stone a){
        return s*a.l < a.s*l;
    }
}stones[N];

int f[N][10010];

int main(){
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n;
        int m =0;
        for(int i=1;i<=n;i++){
            int s,e,l;
            cin>>s>>e>>l;
            m+=s;
            stones[i] = {s,e,l};
        }

        sort(stones+1,stones+1+n);
        for(int i=1;i<=n;i++){
            for(int j =0;j<=m;j++){
                f[i][j] = f[i-1][j];
                if(j>=stones[i].s){
                    int s = stones[i].s;
                    int e = stones[i].e;
                    int l = stones[i].l;
                    f[i][j] = max(f[i][j],f[i-1][j-s] + max(0,e-l*(j-s)));
                }
            }
        }
        int res =0 ;
        for(int i =0;i<=m;i++) res = max(res,f[n][i]);
        printf("Case #%d: %d\n", i, res);
    }

    return 0;
}