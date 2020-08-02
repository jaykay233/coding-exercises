// 这道题的建模过程需要按照三个要求分开建模：
// 规则一：每条路径不相交：
// 因为每条路径不相交，所以每个每个节点只能经过一次。所以我们拆点x,y,顺便将每个点都标号：
// 1.源点向第一层的x集合连一条边，费用为0，容量为1.最后一层的y集合向汇点连一条边，容量为1，费用为0；
// 2.x集合中的每一个点Xi，向y集合中的点Yi连一条边，容量为1，权值为i点的点权，代表每个点只能选一次
// 3.每个Y集合中的点Yi，向x集合的点Xj连一条边，如果j在i的下方或者右下方。
// 之后跑最大费用流，费用即是答案
// 规则二：可以在点处交叉：
// 这次不需要拆点，因为一个点可以经过多次，相当于最长路了
// 1.源点向第一层的每个点连一条边，容量1，费用0；
// 2.最后一层点的向汇点连一条边，容量INF，费用为该点权。
// 3.每一层中的点向下一层的点连一条边，容量为1，费用为点权。代表了只向下一层输送一个点的点权。
// 之后同样跑一次最大费用流。
// 规则三：可以在任意点交叉
// 这个意思其实就是每个点接受的流量可能来自任何一个点，那么问题就简单了，在上面的基础上，将层与层连接的边容量变成INF就行。
// 最大费用流其实不必要重写费用流，只要将权值取相反数就行
// 水题

#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
const int MAXN = 100000;
const int MAXM = 100000;
const int INF = 0x3f3f3f3f;
struct Edge
{
    int from,to,next,cap,flow,cost;
} edge[MAXM];
int head[MAXN],tol;
int pre[MAXN],dis[MAXN];
bool vis[MAXN];
int N;//节点总个数，节点编号从0~N-1
void init(int n)
{
    N = n;
    tol = 0;
    memset(head,-1,sizeof(head));
    memset(edge,0,sizeof(edge));
}
void addedge(int u,int v,int cap,int cost)
{
    edge[tol].from = u;
    edge[tol].to = v;
    edge[tol].cap = cap;
    edge[tol].cost = cost;
    edge[tol].flow = 0;
    edge[tol].next = head[u];
    head[u] = tol++;
    edge[tol].to = u;
    edge[tol].from = v;
    edge[tol].cap = 0;
    edge[tol].cost = -cost;
    edge[tol].flow = 0;
    edge[tol].next = head[v];
    head[v] = tol++;
}
bool spfa(int s,int t)
{
    queue<int>q;
    for(int i = 0; i < N; i++)
    {
        dis[i] = INF;
        vis[i] = false;
        pre[i] = -1;
    }
    dis[s] = 0;
    vis[s] = true;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for(int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].to;
            if(edge[i].cap > edge[i].flow &&
                    dis[v] > dis[u] + edge[i].cost )
            {
                dis[v] = dis[u] + edge[i].cost;
                pre[v] = i;
                if(!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    if(pre[t] == -1)
        return false;
    else
        return true;
}
//返回的是最大流，cost存的是最小费用
int minCostMaxflow(int s,int t,int &cost)
{
    int flow = 0;
    cost = 0;
    while(spfa(s,t))
    {
        int Min = INF;
        for(int i = pre[t]; i != -1; i = pre[edge[i^1].to])
        {
            if(Min > edge[i].cap - edge[i].flow)
                Min = edge[i].cap - edge[i].flow;
        }
        for(int i = pre[t]; i != -1; i = pre[edge[i^1].to])
        {
            edge[i].flow += Min;
            edge[i^1].flow -= Min;
            cost += edge[i].cost * Min;
        }
        flow += Min;
    }
    return flow;
}
void print_all()
{
    for(int i = 0; i<tol; i+=2)
    {
        printf("%d->%d cap = %d flow  = %d cost = %d\n",edge[i].from,edge[i].to,edge[i].cap,edge[i].flow,edge[i].cost);
    }
}
int id[1001][1001];
int a[1001][1001];
int main()
{
    int n,m;
    scanf("%d%d",&m,&n);
    int cnt  =1;
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=i+m-1; j++)
        {
            id[i][j] = cnt++;
            scanf("%d",&a[i][j]);
            a[i][j] = -a[i][j];
        }
    }
    int st = 0,en = cnt * 2+1;
    init(cnt * 2+ 2);
    for(int i = 1; i <= m; i++)
    {
        addedge(st,id[1][i],1,0);
    }
    for(int i = 1; i<=n + m -1; i++)
    {
        addedge(id[n][i] + cnt,en,1,0);
    }
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=i + m -1; j++)
        {
            addedge(id[i][j],id[i][j] + cnt,1,a[i][j]);
            if(i != n)
            {
                addedge(id[i][j] + cnt,id[i+1][j],1,0);
                addedge(id[i][j] + cnt,id[i+1][j+1],1,0);
            }
        }
    }
    int ans1,cost1 = 0;
    ans1 = minCostMaxflow(st,en,cost1);
    printf("%d\n",-cost1);
    init(cnt +2);
    st = 0,en = cnt +1;
    for(int i = 1; i<=m; i++)
    {
        addedge(st,id[1][i],1,0);
    }
    for(int i = 1; i<=n + m -1; i++)
    {
        addedge(id[n][i],en,INF,a[n][i]);
    }
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=i + m -1; j++)
        {
            if( i != n)
            {
                addedge(id[i][j],id[i+1][j],1,a[i][j]);
                addedge(id[i][j],id[i+1][j+1],1,a[i][j]);
            }

        }
    }
    int ans2,cost2 = 0;
    ans2 = minCostMaxflow(st,en,cost2);
    printf("%d\n",-cost2);
    init(cnt +2);
    st = 0,en = cnt +1;
    for(int i = 1; i<=m; i++)
    {
        addedge(st,id[1][i],1,0);
    }
    for(int i = 1; i<=n + m -1; i++)
    {
        addedge(id[n][i],en,INF,a[n][i]);
    }
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=i + m -1; j++)
        {
            if( i != n)
            {
                addedge(id[i][j],id[i+1][j],INF,a[i][j]);
                addedge(id[i][j],id[i+1][j+1],INF,a[i][j]);
            }

        }
    }
    int cost3 = 0;
    int ans3 = minCostMaxflow(st,en,cost3);
    printf("%d\n",-cost3);
    return 0;
}


