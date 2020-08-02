//挑战程序设计竞赛里也有
#include <bits/stdc++.h>
#define AddEdge(x,y,z,f) add_edge(x,y,z,f),add_edge(y,x,-z,0)
using namespace std;
const int MAXN=1e5+10;
const int INF=1e6+10;
typedef long long ll;
inline int read()
{
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int N,K,S,T;
int anscost=0;
struct node
{
    int u,v,w,f,nxt;
}edge[MAXN];
int head[MAXN],num=2;
inline void add_edge(int x,int y,int z,int f)
{
    edge[num].u=x;
    edge[num].v=y;
    edge[num].w=z;
    edge[num].f=f;
    edge[num].nxt=head[x];
    head[x]=num++;
}
int Pre[MAXN],vis[MAXN],dis[MAXN];
int length[MAXN];
bool SPFA()
{
    queue<int>q;
    memset(dis,0xf,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[S]=0;
    q.push(S);
    while(q.size()!=0)
    {
        int p=q.front();q.pop();
        vis[p]=0;
        for(int i=head[p];i!=-1;i=edge[i].nxt)
        {
            if(dis[edge[i].v]>dis[p]+edge[i].w&&edge[i].f)
            {
                dis[edge[i].v]=dis[p]+edge[i].w;
                Pre[edge[i].v]=i;
                if(!vis[edge[i].v])
                    vis[edge[i].v]=1,q.push(edge[i].v);
            }
        }
    }
    return dis[T]<=INF;
}
void f()
{
    int nowflow=INF;
    for(int now=T;now!=S;now=edge[Pre[now]].u)
        nowflow=min(nowflow,edge[Pre[now]].f);
    for(int now=T;now!=S;now=edge[Pre[now]].u)
        edge[Pre[now]].f-=nowflow,
        edge[Pre[now]^1].f+=nowflow;
    anscost+=nowflow*dis[T];
}
void MCMF()
{
    int ans=0;
    while(SPFA())
        f();
    printf("%d\n",-anscost);
}
int L[MAXN],R[MAXN],date[MAXN],tot=0;
int x[MAXN],y[MAXN];
int main()
{
    #ifdef WIN32
    freopen("a.in","r",stdin);
    #else
    #endif
    memset(head,-1,sizeof(head));
    N=read(),K=read();
    for(int i=1;i<=N;i++)
    {
        L[i]=read();R[i]=read();x[i]=read();y[i] = read();
        date[++tot]=L[i],
        date[++tot]=x[i];
        length[i] = sqrt((ll)(L[i]-x[i])*(L[i]-x[i]) + (ll)(R[i]-y[i])*(R[i]-y[i]));
    }
    sort(date+1,date+tot+1);
    int num=unique(date+1,date+2*N+1)-date-1;
    int siz = unique(date+1,date+tot+1) -date-1;
    for(int i =1;i<=N;i++){
        L[i] = lower_bound(date+1,date+siz+1,L[i]) - date;
        x[i] = lower_bound(date+1,date+siz+1,x[i]) - date;
    }
    S=0,T=2*siz+1;
    AddEdge(S,1,K,0);AddEdge(siz<<1,T,K,0);
    for(int i =1;i<(siz<<1);i++) AddEdge(i,i+1,INF,0);
    for(int i=1;i<=N;i++)
        if(L[i]!=x[i]) AddEdge(L[i]<<1|1,x[i]<<1,1,length[i]);
        else AddEdge(L[i]<<1,x[i]<<1|1,1,length[i]);

    MCMF();

    return 0;
}