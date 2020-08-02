#include <bits/stdc++.h>
using namespace std;
int n,m,p;
const int N=1009,M=1e4+5+N*2,INF=1e9;
int idx= 0;
int cost[N],f[(1<<5)+1][N],e[M];
bool inq[N];
int h[N];
int w[M];
int ne[M];
int c;
queue<int> q;

void addEdge(int u,int v,int c){
    e[++idx] = v; w[idx] = c;ne[idx] = h[u];h[u] = idx;
    e[++idx] = u; w[idx] = c;ne[idx] = h[v];h[v] = idx;
}

void spfa(int f[]){
    while(!q.empty()){
        int x = q.front();q.pop(),inq[x] = 0;
        for(int v,i=h[x];i;i=ne[i]){
            if(f[v=e[i]] > f[x] + w[i]){
                f[v] = f[x] + w[i];
                if(!inq[v]) q.push(v),inq[v] = 1;
            }
        }
    }
}


int main(){
    while(~scanf("%d%d%d",&n,&m,&p)){
        memset(f,0x3f,sizeof f);
        memset(h,0,sizeof h);
        idx =0;
        m+=n;
        for(int i =1;i<=n;i++) {
            scanf("%d",&c);
            f[1<<(i-1)][i] = 0;
            addEdge(0,i,c);
        }
        for(int i =n+1;i<=m;i++) {
            scanf("%d",&c);
            addEdge(0,i,c);
        }
        for(int i =0;i<p;i++){
            int w,u,v;
            scanf("%d%d%d",&w,&u,&v);
            addEdge(u,v,w);
        }

        for(int s=1,lim=1<<n;s<lim;s++){
            for(int i =0;i<=m;i++){
                for(int sub=(s-1)&s;sub;sub=(sub-1)&s){
                    f[s][i] = min(f[s][i],f[sub][i] + f[sub^s][i]);
                }
                if(f[s][i]<INF) q.push(i),inq[i] = 1;
            }
            spfa(f[s]);
        }
        printf("%d\n",f[(1<<n)-1][0]);
    }

    return 0;
}