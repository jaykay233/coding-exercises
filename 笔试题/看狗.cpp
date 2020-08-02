#include <bits/stdc++.h>
using namespace std;
int T;
const int N = 1010;
int p[N];
int a[N];
vector<int> dogs[1010];
int f[N][N];
int g[N][N];

int main(){
    scanf("%d",&T);
    for(int C=1;C<=T;C++){
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=1000;i++) dogs[i].clear();
        for(int i=1;i<=n;i++) scanf("%d",&p[i]);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) dogs[a[i]].push_back(p[i]);
        for(int i=1;i<=1000;i++) sort(dogs[i].begin(),dogs[i].end());

        memset(f,0x3f,sizeof f);
        memset(g,0x3f,sizeof g);

        f[0][0] = g[1001][0] = 0;

        for(int i =1;i<=1000;i++){
            for(int j =0;j<=m;j++){
                f[i][j] = f[i-1][j];
                for(int k =0;k < dogs[i].size() && k+1<=j;k++){
                    f[i][j] = min(f[i][j],f[i-1][j-k-1] + dogs[i][k]*2);
                }
            }
        }
        
        for(int i =1000;i>=1;i--){
            for(int j =0;j<=m;j++){
                g[i][j] = g[i+1][j];
                for(int k=0;k<dogs[i].size() && k+1<=j;k++){
                    g[i][j] = min(g[i][j],g[i+1][j - k - 1] + dogs[i][k]*2);
                }
            }
        }
        

        int ans = 1e9;
        for(int i=1;i<=1000;i++)
            for(int j =0;j<dogs[i].size();j++)
                for(int k=0;k + j + 1<=m;k++)
                    ans = min(ans, f[i-1][k] + dogs[i][j] + g[i+1][m-k-j-1]);

        printf("Case #%d: %d\n", C, ans);
    }

    return 0;
}