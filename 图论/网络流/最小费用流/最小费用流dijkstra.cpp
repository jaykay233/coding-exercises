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
 
 
#define MV 11000 //节点最大值
#define INF 0x3f3f3f3f
 
 
struct edge
{
    int t, cap, cost, rev;
    edge(int to = 0, int c = 0, int ct = 0, int r = 0): t(to), cap(c), cost(ct), rev(r) {};
};
vector <edge> G[MV];//图的邻接表表示   注意！如果有多个样例输入 每个样例不要忘记G[i].clear();
int dis[MV];//单源点s到其它顶点的最短距离（本次搜索的最小费用）
int prevv[MV], preve[MV];//最短路中的前驱结点 对应边
int h[MV];
 
//最小费用流Dijkstra算法
 
//Dijkstra算法求最小费用流核心代码：
 
//h[MAX_V]:导入势保证所有边均为非负边 O(FElogV)
typedef pair<int ,int >P;
int min_cost_flow(int n, int v, int s, int t, int f) //与main函数中的变量对应一致
{
    
    int i, ans = 0;
    
    memset(h,0,sizeof h);
    
    while(f > 0)
    {
        //Dijkstra算法：寻找最短路 O(ElogV)
        priority_queue<P, vector<P>, greater<P> > que;
        fill(dis, dis + v, INF);
        dis[s] = 0;
        que.push(P(0, s));
        while(!que.empty())
        {
            P p = que.top();
            que.pop();
            
            int v = p.second;
            if(dis[v] < p.first)
                continue;
            int size = G[v].size();
            
            for(i = 0; i < size; ++i)
            {
                edge es = G[v][i];//****
                if(es.cap > 0 && dis[es.t] > dis[v] + es.cost + h[v] - h[es.t])
                {
                    
                    dis[es.t] = dis[v] + es.cost + h[v] - h[es.t];
                    prevv[es.t] = v;
                    preve[es.t] = i;
                    que.push(P(dis[es.t], es.t));
                }
            }
        }
        
        if(dis[t] == INF)
            return -1;
        //更新势
        for(i = 0; i < v; ++i)
            h[i] += dis[i];
        int d = f;
        for(i = t; i != s; i = prevv[i])
            d = min(d, G[prevv[i]][preve[i]].cap);
        ans += d * h[t];
        
        f -= d;
        
        for(i = t; i != s; i = prevv[i])
        {
            edge &es =  G[prevv[i]][preve[i]];
            es.cap -= d;
            G[i][es.rev].cap += d;
        }
    }
    
    return ans;
}
 
 
void addedge(int s1,int t1,int cap,int cost)
{
    G[s1].push_back(edge(t1, cap, cost, G[t1].size()));
    G[t1].push_back(edge(s1, 0, -cost, G[s1].size() - 1));
}
 
int main()
{
    int n, v, s, t, f;//n 边的条数
                      // v 节点的数量（包括源点和汇点）
                      // s source  t sink
                     // f 需要传送的流量 
    return 0;
}