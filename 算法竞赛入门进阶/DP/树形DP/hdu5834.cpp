#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define clear(a,v) memset(a,(v),sizeof(a))
const int maxn = 1e5+7;
int n, head[maxn], tot,V[maxn];
int dp[maxn][3],id[maxn],ans[maxn];

struct Edge{
    int to,cost,next;
}edges[maxn<<1];

void init(){
    clear(head,-1);tot=0;
    clear(dp,0);
}

void added(int u,int v,int w){
    edges[tot] = Edge{v,w,head[u]};
    head[u] = tot++;
}

void dfs1(int u,int fa){
    dp[u][2] = V[u];
    for(int i = head[u];~i;i=edges[i].next){
        int v = edges[i].to;
        if(v==fa) continue;
        dfs1(v,u);
        dp[u][2] += max(0,dp[v][2] - 2 * edges[i].cost);
    }
    id[u] = -1;
    dp[u][0] = dp[u][1] = V[u];
    for(int i=head[u];~i;i=edges[i].next){
        int ad = edges[i].to;
        int wa = edges[i].cost;
        if(ad == fa) continue;
        int now = dp[u][2] - max(0,dp[ad][2] - 2 * wa) + max(0,dp[ad][0] - wa);
        if( now >= dp[u][0]){
            dp[u][1] = dp[u][0];
            dp[u][0] = now;
            id[u] = ad;
        }
        else if(now > dp[u][1]) dp[u][1] = now;
    }
}

void dfs2(int u,int fa,int up1,int up2){
    ans[u] = max(dp[u][0] + up2,dp[u][2] + up1);
    for(int i=head[u];~i;i=edges[i].next){
        int v = edges[i].to;
        int cost = edges[i].cost;
        if(v==fa) continue;
        int d1,d2;
        if(v==id[u]){
            d1 = max(0,dp[u][1] - max(0,dp[v][2] - 2 * cost));
        }
        else{
            d1 = max(0,dp[u][0] - max(0,dp[v][2] - 2 * cost));
        }

        d2 = max(0,dp[u][2] - max(0,dp[v][2] - 2 * cost));
        d1 = max(0,max(up2 + d1, up1 + d2) - cost);
        d2 = max(0, d2 + up2 - 2* cost);
        dfs2(v,u,d1,d2);
    }
}

int main(){
    int T;scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        init();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&V[i]);
        for(int i=1;i<n;i++){
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            added(u,v,c);added(v,u,c);
        }
        dfs1(1,-1);
        dfs2(1,-1,0,0);
        printf("Case #%d:\n", cas);
        for(int i=1;i<=n;i++){
            printf("%d\n",ans[i]);
        }
    }

    return 0;
}