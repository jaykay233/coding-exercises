#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 3005
#define INF 0x3f3f3f3f

ll mapp[MAXN][MAXN];
ll pre[MAXN];
bool vis[MAXN];
ll dis[MAXN];
vector<int> vec[MAXN];
ll dp[MAXN][MAXN];
int n,m,q;
int u,v;
long long w;
int mst;
ll best[MAXN][MAXN];
ll ans =0;
void init(){
    for(int i =0;i<MAXN;i++){
        for(int j =0;j<MAXN;j++){
            mapp[i][j] = INF;
            dp[i][j] = INF;
        }
        vec[i].clear();
        dis[i] = INF;
    }
    memset(vis,false,sizeof vis);
}

void addEdge(int i,int j){
    vec[i].push_back(j);
    vec[j].push_back(i);
}

ll prim(){
    for(int i =1;i<n;i++){
        dis[i] = mapp[0][i];
        pre[i] = 0;
    }
    int k =0;
    ll mst =0 ;
    dis[0] = INF;
    vis[0] = true;
    pre[0] = -1;
    for(int i =0;i<n-1;i++){
        int t = -1;
        for(int j =0;j<n;j++){
            if(!vis[j] && (t==-1 || dis[t] > dis[j]))
                t = j;
        }
        vis[t] = true;
        mst += dis[t];
        if(pre[t]!=-1)
            addEdge(pre[t],t);
        for(int j=1;j<n;j++){
            if(!vis[j] && dis[j] > mapp[j][k]){
                dis[j] = mapp[j][k];
                pre[j] = k;
            }
        }
    }
    return mst;
}

// root到u及其子树中的距离的最小值

ll dptree(int u,int fa,int root){
    int len = vec[u].size();
    for(int i =0;i<len;i++){
        int v = vec[u][i];
        if(v==fa) continue;
        dp[root][u] = min(dp[root][u],dptree(v,u,root));
    }
    if(root!=fa)
        dp[root][u] = min(dp[root][u],mapp[root][u]);
    return dp[root][u];
}

// 求出u的子树中节点到root的子树的最小值
ll dfs(int u,int fa,int root){
    int len = vec[u].size();
    ll ans = dp[u][root];
    for(int i =0;i<len;i++){
        int v = vec[u][i];
        if(v==fa) continue;
        ll tmp = dfs(v,u,root);
        ans = min(ans,tmp);
    }
    return ans;
}


int main(){
    while(~scanf("%d%d",&n,&m) && n && m){
        init();
        for(int i =0;i<m;i++){
            scanf("%d %d %lld",&u,&v,&w);
            mapp[u][v] = mapp[v][u] = min(mapp[v][u],w);
        }
        mst = prim();
        for(int i =0;i<n;i++){
            dptree(i,-1,i);
        }
        for(int i =0;i<n;i++){
            int len = vec[i].size();
            for(int j=0;j<len;j++){
                int v = vec[i][j];
                best[i][v] = best[v][i] = dfs(v,i,i);
            }
        }
        scanf("%d",&q);
        ans =0 ;
        for(int i =0;i<q;i++){
            scanf("%d %d %lld",&v,&u,&w);
            if(pre[v]!=u && pre[u]!=v){
                ans+=mst;
            }else{
                ans+=mst - mapp[u][v] + min(best[u][v],w);
            }
        }
        printf("%.4lf",ans*1.0/q);
    }

    return 0;
}