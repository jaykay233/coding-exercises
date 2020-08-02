#include <bits/stdc++.h>
using namespace std;
const int N = 110, M = 10010;
int g[N][N];
int n,m;
int dist[N];
bool st[N];
queue<int> q;
const int INF = 0x3f3f3f3f;

void spfa(){
    memset(dist,0x3f,sizeof dist);
    memset(st,false,sizeof st);
    dist[1] = 0;
    q.push(1);
    st[1] = true;
    while(!q.empty()){
        int t = q.front();q.pop();
        st[t] = false;
        for(int i =1;i<=n;i++){
            if(dist[i] > dist[t] + g[t][i]){
                dist[i] = dist[t] = g[t][i];
                if(!st[i]){
                    st[i] = true;
                    q.push(i);
                }
            }
        }
    }    
}

void dijkstra(int u){
    memset(dist,0x3f,sizeof dist);
    memset(st,false,sizeof st);
    dist[u] = 0;
    for(int i=1;i<=n;i++){
        int mi = INF;
        for(int j=1;j<=n;j++){
            if(!st[j] && dist[j] < mi){
                mi = dist[j];
                u = j;
            }
        }
        st[u] = true;
        for(int i =1;i<=n;i++){
            if(g[u][i]!=INF){
                dist[i] = min(dist[i],dist[u] + g[u][i]);
            }
        }
    }
}

int main(){
    while(scanf("%d%d",&n,&m) && n && m){
        memset(g,0x3f,sizeof g);
        for(int i=1;i<=m;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            g[a][b] = g[b][a] = min(g[a][b],c);
        }
        // spfa();
        dijkstra(1);
        cout<<dist[n]<<endl;
    }

    return 0;
}