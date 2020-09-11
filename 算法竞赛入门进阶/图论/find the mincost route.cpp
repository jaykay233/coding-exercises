//无向图最小环
#include <bits/stdc++.h>
using namespace std;
int n,m;
const int INF=0xfffffff;
const int NUM=1e2+10;
int graph[NUM][NUM];
int dis[NUM][NUM];
int a,b,c;
int ans = INF;

void floyd(){
    int ans = INF;
    for(int k=1;k<=n;k++){
        for(int i =1;i<k;i++){
            for(int j=1;j<i;j++){
                ans = min(ans,dis[i][k] + dis[k][j] + graph[i][j]);
            }
        }
        for(int i=1;i<=n;i++){
            if(graph[i][k]!=INF)
            for(int j=1;j<=n;j++){
                if(graph[i][j]>=graph[i][k]+graph[k][j]){
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
    if(ans >= INF) printf("It's impossible.\n");
    else printf("%d\n",ans);
}

int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j){
                    graph[i][j]=INF;
                    dis[i][j] = INF;
                }
            }
            graph[i][i] = dis[i][i] = 0;
        }
        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&a,&b,&c);
            if(a!=b)
                graph[a][b] = graph[b][a] = dis[a][b] = dis[b][a] = min(graph[a][b],c);
        }
        floyd();
    }
    return 0;
}