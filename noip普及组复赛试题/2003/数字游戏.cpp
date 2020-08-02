#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 110, M = 10, INF = 0x3f3f3f3f;
int w[N];
int f[N][N][M];
int g[N][N][M];
int s[N];

int get_mod(int sum){
    return (sum%10+10)%10;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(int i =1;i<=n;i++){
        w[n+i] = w[i];
    }
    for(int i =1;i<=2*n;i++) s[i] = s[i-1] + w[i];
    
    memset(f,0x3f,sizeof f);
    memset(g,-0x3f,sizeof g);
    
    
    for (int len = 1; len <= n; len ++ )
        for (int l = 1; l + len - 1 <= n * 2; l ++ )
        {
            int r = l + len - 1;
            f[l][r][1] = g[l][r][1] = get_mod(s[r] - s[l - 1]);
            for(int k = 2;k<=m;k++){
                for(int j = l+k-2;j<r;j++){
                    f[l][r][k] = min(f[l][r][k],f[l][j][k-1] * get_mod(s[r] - s[j]));
                    g[l][r][k] = max(g[l][r][k],g[l][j][k-1] * get_mod(s[r] - s[j]));
                }
            }
        }
    
    int maxv = -INF, minv = INF;
    for (int i = 1; i <= n; i ++ )
    {
        maxv = max(maxv, g[i][i+n-1][m]);
        minv = min(minv, f[i][i+n-1][m]);
    }

    cout << minv << endl;
    cout << maxv << endl;
    
    
    return 0;
}