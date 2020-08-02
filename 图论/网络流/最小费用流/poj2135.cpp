#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
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

int n,m;
int main(){
    scanf("%d%d",&n,&m);
    int s = 0, t = n-1;
    V = n;
    for(int i =0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add_edge(a-1,b-1,1,c);
        add_edge(b-1,a-1,1,c);
    }
    printf("%d\n",min_cost_flow(s,t,2));
    return 0;
}