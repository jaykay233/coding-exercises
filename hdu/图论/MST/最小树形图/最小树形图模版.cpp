#include <bits/stdc++.h>
using namespace std;
int n,X,Y,Z;
const int N = 1010;
int in[N];
#define inf 0x3f3f3f3f
struct edge{
    int u,v,w;
}edge[N];
int pre[N];
int id[N];
int use[N];

void readin(){

}

int zhuliu(int root,int n,int m){
    int ans =0;
    int i,u;
    while(true){
        for(int i=1;i<=n;i++)
            in[i] = inf;
        for(int i=1;i<=m;i++){
            int u = edges[i].u;
            int v = edges[i].v;
            if(edges[i].w < in[v] && u!=v){
                in[v] = edges[i].w;
                pre[v] = u;
            }
        }

        for(int i=1;i<=n;i++){
            if(i==root) continue;
            if(in[i]==inf) return -1;
            ans+=in[i];
        }
        memset(use,-1,sizeof use);
        memset(id,-1,sizeof id);
        int cnt = 0;
        for(int i=1;i<=n;i++){
            int v = i;
            while(v!=root && id[v]==-1 && use[v]!=i){
                use[v] = i;
                v = pre[v];
            }
            if(v!= root && id[v]==-1){
                id[v] = ++cnt;
                for(u=pre[v];u!=v;u=pre[u])
                    id[u] = cnt;
            }
        }
        if(cnt==0) break;
        for(i=1;i<=n;i++)
            if(id[i]==-1)
                id[i] = ++cnt;
        for(int i=1;i<=m;i++){
            int u = edge[i].u;
            int v = edge[i].v;
            edge[i].u = id[u];
            edge[i].v = id[v];
            if(edge[i].v!=edge[i].u)
                edge[i].w -= in[v];
        }
        n = cnt;
        root = id[root];
    }
    return ans;
}


int main(){
    scanf("%d%d%d%d",&n,&X,&Y,&Z);
    readin();

    return 0;
}