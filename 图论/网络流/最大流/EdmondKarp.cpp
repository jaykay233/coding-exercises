#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

const int N=1e4+5,M=2e5+5;
int n,m,s,t,tot=1,lnk[N],ter[M],nxt[M],val[M],pre[N],idx[N];
bool vis[N];

void add(int u,int v,int w) {
    ter[++tot]=v,nxt[tot]=lnk[u],lnk[u]=tot,val[tot]=w;
}
bool bfs(int s,int t) {
    memset(pre,0,sizeof(pre));
    memset(vis,0,sizeof(vis));
    std::queue<int> q;
    q.push(s),vis[s]=1;
    while(!q.empty()) {
        int u=q.front(); q.pop();
        for(int i=lnk[u];i;i=nxt[i]) {
            int v=ter[i];
            if(!vis[v]&&val[i]) {
                pre[v]=u,idx[v]=i,q.push(v),vis[v]=1;
                if(v==t) return 1;
            }
        }
    }
    return 0;
}
int EK(int s,int t) {
    int ans=0;
    while(bfs(s,t)) {
        int mn=1<<30;
        for(int i=t;i!=s;i=pre[i]) mn=std::min(mn,val[idx[i]]);
        for(int i=t;i!=s;i=pre[i]) {
            int x=idx[i];
            val[x]-=mn,val[x^1]+=mn;
        }
        ans+=mn;
    }
    return ans;
}
int main() {
    scanf("%d%d%d%d",&n,&m,&s,&t);
    while(m--) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w),add(v,u,0);
    }
    printf("%d\n",EK(s,t));
    return 0;
}