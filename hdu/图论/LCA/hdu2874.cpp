#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
int dep[N];
int p[N][20];
int dis[N];
int root[N];
int n;
const int M = 10010;
int e[M],ne[M],w[M];
int idx=0;
int h[N];
int fa[N][20];
int depth[N];

void init(){
    memset(h,-1,sizeof h);
    idx =0 ;
    memset(dis,0,sizeof dis);
    memset(root,0,sizeof root);
}

void add(int u,int v,int c){
    e[idx] = v;w[idx] = c;ne[idx] = h[u];h[u] = idx++;
}

void dfs(int u,int f,int d,int id){
    depth[u] = d;
    fa[u][0] = f;
    root[u] = id;
    for(int i =h[u];i!=-1;i=ne[i]){
        int j = e[i];
        if(j==f) continue;
        dis[j] = dis[u] + w[i];
        dfs(j,u,d+1,id);
    }
}

void climb(){
    for(int j=1;j<20;j++)
        for(int i=1;i<=n;i++)
            fa[i][j] = fa[fa[i][j-1]][j-1];
}

int lca(int u,int v){
    if(depth[u] > depth[v]) swap(u,v);
    for(int k=19;k>=0;k--){
        if(depth[fa[u][k]]>=depth[v])
            u = fa[u][k];
    }
    if(u==v) return u;
    for(int k=19;k>=0;k--){
        if(fa[u][k]!=fa[v][k]){
            u = fa[u][k];
            v = fa[v][k];
        }
    }
    return fa[u][0];
}

int main(){
    int m,k;
    while(~scanf("%d%d%d",&n,&m,&k)){
        int a,b,c;
        init();
        for(int i =0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c);
            add(b,a,c);
        }
        for(int i=1;i<=n;i++){
            if(!root[i])
                dfs(i,0,0,i);
        }
        climb();
        for(int i =0;i<k;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            if(root[u]!=root[v]){
                printf("Not connected\n");
            }
            else
                printf("%d\n",dis[u] + dis[v] - dis[lca(u,v)]);
        }
    }
    return 0;
}