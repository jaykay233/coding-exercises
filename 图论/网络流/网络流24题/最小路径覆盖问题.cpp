#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
const int maxn=1000001;
const int inf=1e9;
queue <int> q;
int n,m,k,maxflow,a[maxn],S,T;
struct Edge{
    int next,to,dis;
}edge[maxn<<1];
int num_edge=-1,head[maxn],cur[maxn],deep[maxn];
int nxt[maxn],pre[maxn];//分别表示点i的前一个点和后一个点是什么 

void add_edge(int from,int to,int dis)
{
    edge[++num_edge].next=head[from];
    edge[num_edge].dis=dis;
    edge[num_edge].to=to;
    head[from]=num_edge;
}
void add(int x,int y,int z) {add_edge(x,y,z); add_edge(y,x,0);}

bool bfs(int s,int t)
{
    memset(deep,0x7f,sizeof(deep));
    for (int i=0; i<=t; i++) cur[i]=head[i];
    while (!q.empty()) q.pop();
    q.push(s); deep[s]=0;
    while (!q.empty())
    {
        int now=q.front(); q.pop();
        for (int i=head[now]; i!=-1; i=edge[i].next)
        {
            int to=edge[i].to;
            if (deep[to]>inf && edge[i].dis)
            {
                deep[to]=deep[now]+1;
                q.push(to);
            }
        }
    }
    return deep[t]<inf;
}

int dfs(int now,int t,int limit)
{
    if (now==t || !limit) return limit;
    int flow=0,f;
    for (int i=cur[now]; i!=-1; i=edge[i].next)
    {
        int to=edge[i].to; cur[now]=i;
        if (deep[to]==deep[now]+1 && (f=dfs(to,t,min(limit,edge[i].dis))))
        {
            flow+=f;
            limit-=f;
            edge[i].dis-=f;
            edge[i^1].dis+=f;
            if (!limit && now!=S && to!=T) nxt[now]=to-n; pre[to-n]=now;
            if (!limit) break;
        }
    }
    return flow;
}

void Dinic(int s,int t)
{
    while (bfs(s,t))
        maxflow+=dfs(s,t,inf);
}
bool vis[maxn];
void print(int x)
{
    if (!x) return;//到达了源点 
    if (pre[x]!=x) print(pre[x]);
    vis[x]=1;
    printf("%d ",x);
}

int main()
{
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&m);
    S=0; T=2*n+1;
    for (int i=1; i<=n; i++) nxt[i]=pre[i]=i;
    for (int i=1; i<=n; i++) {add(S,i,1); add(i+n,T,1);}
    for (int i=1; i<=m; i++)
    {
        int x,y; scanf("%d%d",&x,&y);
        add(x,y+n,1);
    }
    Dinic(S,T);
    for (int i=n; i>=1; i--)
        if (nxt[i]==i && !vis[i]) {print(i); printf("\n");}
    printf("%d",n-maxflow);
    return 0;
}