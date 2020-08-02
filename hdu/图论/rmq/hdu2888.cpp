//二维rmq模版
#include <bits/stdc++.h>
using namespace std;
double eps = 1e-8;
int n,m;
const int N = 301;
int dp[N][N][9][9];
int a[N][N];

void init_rmq()
{
    for ( int i = 1 ; i <= n ; i++)
    for ( int j = 1; j <= m ; j++) dp[i][j][0][0] = a[i][j];
    
    for ( int i = 0 ; (1<<i)<= n ; i++)
    for ( int j = 0 ; (1<<j)<= m  ;j++)
        if (i==0&&j==0) continue;
        else for ( int p = 1 ; p + (1<<i)-1 <= n ; p++)
              for ( int q = 1 ; q + (1<<j)-1 <= m ;q ++)
              if (i==0)
                  dp[p][q][i][j] = max(dp[p][q][i][j-1],dp[p][q+(1<<(j-1))][i][j-1]);
              else dp[p][q][i][j] = max(dp[p][q][i-1][j],dp[p+(1<<(i-1))][q][i-1][j]);
    
}

//因为不一定能正好覆盖,所以分成四块
int rmq_max(int x1,int y1,int x2,int y2)
{
    int k1 = 0 ;
    int k2 = 0 ;

    while (1<<(k1+1)<=x2-x1+1) k1++;
    while (1<<(k2+1)<=y2-y1+1) k2++;

    int tmp1 = dp[x1][y1][k1][k2];
    int tmp2 = dp[x2-(1<<k1)+1][y1][k1][k2];
    int tmp3 = dp[x1][y2-(1<<k2)+1][k1][k2];
    int tmp4 = dp[x2-(1<<k1)+1][y2-(1<<k2)+1][k1][k2];

    return max(max(tmp1,tmp2),max(tmp3,tmp4));
}



int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
        init_rmq();
        int q;
        scanf("%d",&q);
        for(int i=1;i<=q;i++){
            int x1,x2,y1,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            int mx = rmq_max(x1,y1,x2,y2);
            if(mx==a[x1][y1] || mx==a[x2][y1] || mx==a[x1][y2] || mx==a[x2][y2]){
                printf("%d yes\n", mx);
            }
            else{
                printf("%d no\n", mx);
            }
        }
    }

    return 0;
}