#include <bits/stdc++.h>
using namespace std;
int T;
int n,m;
const int N = 40010;
const int M = 210;
int h[N];
int e[M],ne[M],w[M];
int idx;
int q[N];
bool in[N];
int root;
int depth[N];
int fa[N][16];
int dist[N];

void init(){
    memset(h,-1,sizeof h);
    idx = 0;
    memset(in,false,sizeof in);
    memset(dist,0,sizeof dist);
}


void add(int u,int v,int c){
    e[idx] =v;w[idx] = c;ne[idx] = h[u];h[u] = idx++;
}

void bfs(){
    memset(depth,0x3f,sizeof depth);
    depth[0] = 0;
    depth[root] = 1;
    int hh =0 ,tt =0 ;
    q[0] = root;
    while(hh<=tt){
        int t = q[hh++];
        for(int i = h[t];i!=-1;i=ne[i]){
            int j = e[i];
            if(depth[j]> depth[t] + 1){
                depth[j] = depth[t] + 1;
                dist[j] = dist[t] + w[i];
                q[++tt] = j;
                fa[j][0] = t;
                for(int k=1;k<=15;k++)
                    fa[j][k] = fa[fa[j][k-1]][k-1];
            }
        }
    }
}

int lca(int a,int b){
    if(depth[a]<depth[b]) swap(a,b);
    for(int k=15;k>=0;k--){
        if(depth[fa[a][k]]>=depth[b])
            a = fa[a][k];
    }
    if(a==b) return a;
    for(int k=15;k>=0;k--){
        if(fa[a][k]!=fa[b][k]){
            a = fa[a][k];
            b = fa[b][k];
        }
    }
    return fa[a][0];
}




int main(){
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        scanf("%d%d",&n,&m);
        int u,v,c;
        init();
        for(int i=1;i<=n-1;i++){
            scanf("%d%d%d",&u,&v,&c);
            add(u,v,c);
            in[v] = true;
        }
        for(int i=1;i<=n;i++){
            if(!in[i]) root = i;
        }
        bfs();

        for(int i=1;i<=m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            int f = lca(u,v);
            printf("%d\n",dist[u] + dist[v] - 2*dist[f]);
        }
    }
    return 0;
}