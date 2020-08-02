#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>
using namespace std;
#define MAX 50000
#define MAXL 500000
#define INF 1000000000
inline int read()
{
    int x=0,t=1;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-')t=-1,ch=getchar();
    while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
    return x*t;
}
struct Line
{
    int v,next,w,fy;
}e[MAXL];
int h[MAX],cnt=2;
inline void Add(int u,int v,int w,int fy)
{
    e[cnt]=(Line){v,h[u],w,fy};h[u]=cnt++;
    e[cnt]=(Line){u,h[v],0,-fy};h[v]=cnt++;
}
int pe[MAX],pr[MAX],dis[MAX];
bool vis[MAX];
int S,T,Cost,n,m,Flow,sum;
int ff[MAXL];
int ss[MAX],tt=0;
bool SPFA()
{
    memset(dis,63,sizeof(dis));
    queue<int> Q;
    Q.push(S);dis[S]=0;
    while(!Q.empty())
    {
        int u=Q.front();Q.pop();
        for(int i=h[u];i;i=e[i].next)
        {
            int v=e[i].v;
            if(e[i].w&&dis[v]>dis[u]+e[i].fy)
            {
                dis[v]=dis[u]+e[i].fy;
                pe[v]=i;pr[v]=u;
                if(!vis[v])vis[v]=true,Q.push(v);
            }
        }
        vis[u]=false;
    }
    if(dis[T]>=INF)return false;
    int flow=INF;
    for(int i=T;i!=S;i=pr[i])flow=min(flow,e[pe[i]].w);
    for(int i=T;i!=S;i=pr[i])e[pe[i]].w-=flow,e[pe[i]^1].w+=flow;
    Cost-=flow*dis[T];
    Flow+=flow;
    return true;
}
int Cnt(int x,int y){return x*m+y-m;}
int K,g[50][50];
void DFS(int x,int y)
{
    int now=Cnt(x,y),d0=Cnt(x+1,y),d1=Cnt(x,y+1);
    for(int i=h[now+n*m];i;i=e[i].next)
    {
        if(ff[i]>=e[i^1].w)continue;//流满
        if(e[i].v==d0)
        {
            ff[i]++;ss[++tt]=0;
            DFS(x+1,y);
            return;
        }
        else if(e[i].v==d1)
        {
            ff[i]++;ss[++tt]=1;
            DFS(x,y+1);
            return;
        }
    }
}
int main()
{
    K=read();m=read();n=read();
    S=0;T=n*m*2+1;
    Add(S,1,K,0);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            g[i][j]=read();
            if(g[i][j]==2)Add(Cnt(i,j),Cnt(i,j)+n*m,1,-1);
        }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(g[i][j]!=1)Add(Cnt(i,j),Cnt(i,j)+n*m,INF,0);
    Add(T-1,T,K,0);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            if(g[i][j]==1)continue;
            if(i!=n&&g[i+1][j]!=1)Add(Cnt(i,j)+n*m,Cnt(i+1,j),INF,0);
            if(j!=m&&g[i][j+1]!=1)Add(Cnt(i,j)+n*m,Cnt(i,j+1),INF,0);
        }
    while(SPFA());
    for(int i=1;i<=Flow;++i)
    {
        tt=0;DFS(1,1);
        for(int j=1;j<=tt;++j)printf("%d %d\n",i,ss[j]);
    }
    return 0;
}