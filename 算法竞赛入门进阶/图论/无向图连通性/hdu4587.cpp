//枚举一个点删除，然后再枚举另一个看割除后有几个分支
#include <bits/stdc++.h>
using namespace std;
const int inf = 1<<20;
struct node{
    int to;
    int next;
    node(){}
    node(int a,int b):to(a),next(b){}
}edge[5005<<1];

int head[5005],vis[5005],dfn[5005],low[5005],cut[5005];
int tot,ti,root;
int n,m;


void add_edge(int u,int v){
    edge[tot] = node(v,head[u]);
    head[u] = tot++;
    edge[tot] = node(u,head[v]);
    head[v] = tot++;
}

void init(){
    memset(vis,0,sizeof vis);
    memset(dfn,0,sizeof dfn);
    memset(cut,0,sizeof cut);
    memset(low,0,sizeof low);
    ti=0;
}

void tarjan(int u,int fa,int k){
    dfn[u]=++ti;low[u]=ti;vis[u]=1;
    int tot=0;
    for(int i = head[u];i!=-1;i=edge[i].next){
        int v = edge[i].to;
        if(v==k) continue;
        if(!dfn[v]){
            tarjan(v,u,k);
            low[u]=min(low[u],low[v]);
            tot++;
            if(dfn[u]<=low[v]){
                cut[u]++;
            }
        }
        else if(vis[v]==1 && v!=fa) low[u] = min(low[u],dfn[v]);
    }
    vis[u]=2;
    if(u==root) cut[u] = tot-1;
}

int main(){
    int u,v;
    while(scanf("%d%d",&n,&m)!=EOF){
        tot =0;
        memset(head,-1,sizeof head);
        for(int i=0;i<m;i++){
            scanf("%d%d",&u,&v);
            add_edge(u,v);
        }
        int res = 0;
        for(int i =0;i<n;i++){
            init();
            int sum = 0;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(!dfn[j]) {root=j;tarjan(j,-1,i);sum++;}
            }
            for(int j =0;j<n;j++){
                if(j!=i) res = max(res,sum + cut[j]);
            }
        }
        printf("%d\n",res);
    }
    return 0;
}


