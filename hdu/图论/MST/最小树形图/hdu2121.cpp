#include <bits/stdc++.h>
using namespace std;
#define maxn 1008
#define ll long long
struct {
    int u,v;
    ll w;
}edge[maxn*20];

int pre[maxn],vis[maxn],id[maxn],n,m,tmp;
ll sum,in[maxn];
const int INF = 0x3f3f3f3f;
int pos;

ll zhuliu(int root, int n, int m) {
    ll ans = 0;
    while(true) {
        for (int i = 0; i < n; i++) in[i] = INF;
        for (int i = 0; i < m; i++) {
            int u = edge[i].u, v = edge[i].v;
            if (u != v && edge[i].w < in[v]) {
                in[v] = edge[i].w;
                pre[v] = u;
                if (u == root) {
                    pos = i;/*pos = v-1*/
                }
            }
        }
        for(int i=0 ; i<n ; i++)
            if (in[i] == INF && i!=root) return -1;
        int cnt = 0;
        memset(id,-1,sizeof id);
        memset(vis,-1,sizeof vis);
        in[root] = 0;
        for(int i=0 ; i<n ; i++) {
            ans += in[i];
            int v = i;
            while(vis[v] != i && id[v] == -1 && v!=root) {
                vis[v] = i;
                v = pre[v];
            }
            if(v != root && id[v] == -1) {
                for(int u = pre[v] ; u!=v ; u = pre[u])
                    id[u] = cnt;
                id[v] = cnt++;
            }
        }
        if(cnt == 0) break;
        for(int i=0 ; i<n ; i++) if(id[i] == -1) id[i] = cnt++;
        for(int i=0 ; i<m ; i++) {
            int v = edge[i].v;
            edge[i].u = id[edge[i].u];
            edge[i].v = id[edge[i].v];
            if(edge[i].u != edge[i].v) edge[i].w -= in[v];
        }
        n = cnt;
        root = id[root];
    }
    return ans;
}

int main(){
    while(~scanf("%d%d",&n,&m)){
        sum = 0;
        for(int i =0;i<m;i++){
            scanf("%d%d%lld",&edge[i].u,&edge[i].v,&edge[i].w);
            edge[i].u++;edge[i].v++;
            sum+=edge[i].w;
        }
        sum++, tmp = m;
        for(int i =1;i<=n;i++){
            edge[tmp].u = 0;
            edge[tmp].v = i;
            edge[tmp++].w = sum;
        }
        ll ans = zhuliu(0,n+1,n+m);
        if(ans==-1 || ans>=2*sum) puts("impossible");
        else printf("%lld %d\n",ans-sum,pos-m);
        putchar('\n');
    }
    return 0;
}