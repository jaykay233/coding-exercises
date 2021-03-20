#include<iostream>
#include<vector>
using namespace std;
int N,M;
int val[205];
int vis[205];
int dp[205][205];
vector<int> tree[205];

int max(int a,int b)
{
    return a>b?a:b;
}

void dfs(int x)
{
    int i,j,k;
    vis[x]=1;
    dp[x][0]=0;

    for(i=0;i<tree[x].size();i++){
        int to = tree[x][i];
        dfs(to);
        for(int j=M+1;j>=1;j--){
            for(int k=0;k<j;k++){
                dp[x][j] = max(dp[x][j],dp[x][j-k] + dp[to][k]);
            }
        }
    }
    for(int i=M+1;i>=1;i--) dp[x][i] = max(dp[x][i],dp[x][i-1] + val[x]);
}

int main()
{
    while(scanf("%d%d",&N,&M)!=EOF&&(N||M))
    {
        int i,a,b;
        for(i=0;i<=N;i++)
            tree[i].clear();
        for(i=1;i<=N;i++)
        {
            scanf("%d%d",&a,&b);
            tree[a].push_back(i);
            val[i]=b;
        }

        val[0]=0;
        memset(vis,0,sizeof(vis));
        memset(dp,-1,sizeof(dp));
        dfs(0);
        printf("%d\n",dp[0][M+1]);
    }
    return 0;
}