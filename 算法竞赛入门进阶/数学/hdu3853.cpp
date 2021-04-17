#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
const int MAXN=2001;
const int INF=0x7fffff;
double dp[MAXN][MAXN];//走到i，j的期望
struct node
{
    double a,b,c;
    void clear(){a=b=c=0.0;}
}map[MAXN][MAXN];
int n,m;
const double eps=1e-5;
int main()
{
    dp[n][m]=0;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(dp,0.00,sizeof(dp));
        dp[n][m]=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                map[i][j].clear();
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%lf%lf%lf",&map[i][j].a,&map[i][j].b,&map[i][j].c);
        for(int i=n;i>=1;i--)
            for(int j=m;j>=1;j--)
            {
                if(i==n&&j==m)    continue;
                if(fabs(1.00-map[i][j].a)<eps)    continue;
                dp[i][j]=(map[i][j].b*dp[i][j+1]+map[i][j].c*dp[i+1][j]+2.00)/(1.0-map[i][j].a);
            }
        printf("%.3lf\n",dp[1][1]);
    }
    return 0;
}