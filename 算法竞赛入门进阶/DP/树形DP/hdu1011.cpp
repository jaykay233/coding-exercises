#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
bool vis[maxn];
vector<int> tree[maxn];
int cost[maxn],value[maxn];
int n,m;
int dp[maxn][maxn];

void dfs(int root){
    vis[root] = true;
    int temp = (cost[root] + 19)/20;
    for(int i=temp;i<=m;i++)
        dp[root][i] = value[root];
    for(int i =0;i<tree[root].size();i++){
        int t = tree[root][i];
        if(vis[t]) continue;
        dfs(t);
        for(int j = m;j>=temp;j--){
            for(int k=1;k+temp<=j;k++){
                dp[root][j] = max(dp[root][j],dp[root][j-k] + dp[t][k]);
            }
        }
    }
}

int main(){
    while(scanf("%d%d",&n,&m)!=EOF && n!=-1 && m!=-1){
        for(int i =0;i<maxn;i++) tree[i].clear();
        memset(vis,false,sizeof vis);
        memset(dp,0,sizeof dp);
        for(int i=1;i<=n;i++)
            scanf("%d%d",&cost[i],&value[i]);
        for(int i=1;i<n;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        if(m==0) cout<<0<<endl;
        else{
            dfs(1);
            cout<<dp[1][m]<<endl;
        }
    }
    return 0;
}