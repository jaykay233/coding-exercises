#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
int T;
int N,M;
const int MAXN = 55;
const int MAXM = 55;
int z[MAXN][MAXM];
#define MAX_V 10010
const int INF = INT_MAX;

//用于表示边的结构体(终点，容量，费用反向边)
struct edge
{
    int to,cap,cost,rev;
};

int V;//顶点数
vector<edge> G[MAX_V];//图的邻接表表示
int dist[MAX_V];//最短距离
int prevv[MAX_V],preve[MAX_V];//最短路中的前驱结点和对应的边

//向图中增加一条从from到to容量为cap费用为cost的边
void add_edge(int from,int to,int cap,int cost)
{
    G[from].push_back((edge){to,cap,cost,(int)G[to].size()});
    G[to].push_back((edge){from,0,-cost,(int)G[from].size()-1});
}
//求解从s到t流量为f的最小费用流
//如果不能再增广则返回-1
int min_cost_flow(int s,int t,int f)
{
    int res=0;
    while(f>0){
        //利用Bellman-Ford算法求解从s到t的最短路
        fill(dist,dist+V,INF);
        dist[s]=0;
        bool update=true;
        while(update){
            update=false;
            for(int v=0;v<V;v++){
                if(dist[v]==INF) continue;
                for(int i=0;i<G[v].size();i++){
                    edge &e=G[v][i];
                    if(e.cap>0&&dist[e.to]>dist[v]+e.cost){
                        dist[e.to]=dist[v]+e.cost;
                        prevv[e.to]=v;
                        preve[e.to]=i;
                        update=true;
                    }
                }
            }
        }
        if(dist[t]==INF){
            //不能再增广
            return -1;
        }
        //沿s到t的最短路尽量增广
        int d=f;
        for(int v=t;v!=s;v=prevv[v]){
            d=min(d,G[prevv[v]][preve[v]].cap);
        }
        f-=d;
        res+=d*dist[t];
        for(int v=t;v!=s;v=prevv[v]){
            edge &e=G[prevv[v]][preve[v]];
            e.cap-=d;
            G[v][e.rev].cap+=d;
        }
    }
    return res;
}
int main(){
    scanf("%d",&T);
    for(int i =1;i<=T;i++){
        scanf("%d%d",&N,&M);
        int s = N + N*M, t =s+1;
        V = t + 1;
        memset(z,0,sizeof z);
        for(int i =0;i<MAX_V;i++) G[i].clear();
        memset(dist,0x3f,sizeof dist);
        memset(preve,0,sizeof preve);
        memset(prevv,0,sizeof prevv);

        for(int i =0;i<N;i++){
            for(int j =0;j<M;j++){
                scanf("%d",&z[i][j]);
            }
        }
        for(int i =0;i<N;i++){
            add_edge(s,i,1,0);
        }
        for(int j =0;j<M;j++){
            for(int k=0;k<N;k++){
                add_edge(N+j*N+k,t,1,0);
                for(int i =0;i<N;i++){
                    add_edge(i,N+j*N+k,1,(k+1)*z[i][j]);
                }
            }
        }

        printf("%.6f\n",(double) min_cost_flow(s,t,N)/N);
    }


    return 0;
}