#include<complex>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=201,M=1001;
struct node{
    int v,f,w,nxt;
}e[M<<1];
int n,s,t,Enum=1;
long long num;
int front[N],dis[N],path[N],a[N],incf[N];
bool vis[N];
queue<int>q;
int qread()
{
    int x=0;
    char ch=getchar();
    while(ch<'0' || ch>'9')ch=getchar();
    while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}
void Insert(int u,int v,int f,int w)
{
    e[++Enum].v=v;e[Enum].f=f;e[Enum].w=w;e[Enum].nxt=front[u];front[u]=Enum;
    e[++Enum].v=u;e[Enum].f=0;e[Enum].w=-w;e[Enum].nxt=front[v];front[v]=Enum;
}
bool SPFA()
{
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[s]=0;q.push(s);
    incf[s]=INF;
    int u,v;
    while(!q.empty())
    {
        u=q.front();q.pop();
        vis[u]=0;
        for(int i=front[u];i;i=e[i].nxt)
        {
            v=e[i].v;
            if(e[i].f && dis[v]>dis[u]+e[i].w)
            {
                dis[v]=dis[u]+e[i].w;
                incf[v]=min(incf[u],e[i].f);
                path[v]=i;
                if(!vis[v])
                {
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
    return dis[t]<INF;
}
int CostFlow()
{
    int res=0;
    while(SPFA())
    {
        int x=t;
        while(x!=s)
        {
            int i=path[x];
            e[i].f-=incf[t];
            e[i^1].f+=incf[t];
            x=e[i^1].v;
        }
        res+=dis[t]*incf[t];
    }
    return res;
}
