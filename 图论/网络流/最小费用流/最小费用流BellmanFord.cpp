// Bellman_Ford
//Bellman—Ford算法
 
//Bellman算法求最短增广路&最小费用流 O(FEV)
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>
#include<stack>
#include<queue>
#include<cmath>
#include<stack>
#include<list>
#include<map>
#include<set>
typedef long long ll;
using namespace std;
#define MV 11000 //顶点的最大个数
#define INF 0x3f3f3f3f
 
struct edge
{
    int t, cap, cost, rev;
    edge(int to = 0, int c = 0, int ct = 0, int r = 0): t(to), cap(c), cost(ct), rev(r) {};
};
vector <edge> G[MV];
int dis[MV];//the distance from source
int prevv[MV], preve[MV];//the previous node and the previous edge
 
int min_cost_flow(int n,int v,int s, int t, int f)//与main函数中的变量意义相同
{
    
    int ans = 0, i, j;
    while(f > 0)
    {
        fill(dis, dis + v, INF);
        dis[s] = 0;
        bool update = true;
        while(update)
        {//bellman
            update = false;
            for(i = 0; i < v; ++i)
            {
                int size1 = G[i].size();
                if(dis[i] == INF)
                    continue;
                for(j = 0; j < size1; ++j)
                {
                    edge &es = G[i][j];
                    if(es.cap > 0 && dis[es.t] > dis[i] + es.cost)
                    {
                        dis[es.t] = dis[i] + es.cost;
                        prevv[es.t] = i;
                        preve[es.t] = j;
                        update = true;
                    }
                }
            }
        }
        
        if(dis[t] == INF)
            return -1;
        int d = f;
        for(i = t; i != s; i = prevv[i])
            d = min(d, G[prevv[i]][preve[i]].cap);
        
        ans += d * dis[t];
        f -= d;
        for(i = t; i != s; i = prevv[i])
        {
            edge &es = G[prevv[i]][preve[i]];
            es.cap -= d;
            G[es.t][es.rev].cap += d;
        }
    }
    return ans;
}
 
 
void addedge(int s1,int t1,int cap,int cost)//依次为边的起点 终点 容量 花费
{
    G[s1].push_back(edge(t1, cap, cost, G[t1].size()));
    G[t1].push_back(edge(s1, 0, -cost, G[s1].size() - 1));
}
int main()
{
    int n, v, s, t, f;//n 是边的条数
                      // v 节点的个数（包括源点和汇点）
                      // s source   t sink
                     // f为需要传送的流量
    return 0;
}