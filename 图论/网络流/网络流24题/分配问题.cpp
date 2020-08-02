//https://www.cnblogs.com/guapisolo/p/10283836.html
//费用流
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N1 205
#define M1 50010
#define ll long long
#define dd double
#define inf 0x3f3f3f3f
using namespace std;

int gint()
{
    int ret=0,fh=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')fh=-1;c=getchar();}
    while(c>='0'&&c<='9'){ret=ret*10+c-'0';c=getchar();}
    return ret*fh;
}

int n,nn,S,T;


int flow[N1][N1],cost[N1][N1],f[N1][N1],c[N1][N1];
int que[M1],hd,tl,C[N1],F[N1],pre[N1];

namespace S1{
void bfs()
{
    int x,i,v;
    memset(C,0x3f,sizeof(C)); memset(F,0,sizeof(F)); 
    hd=1,tl=0; que[++tl]=S; C[S]=0; F[S]=inf;
    while(hd<=tl)
    {
        x=que[hd++];
        for(v=1;v<=nn;v++)
        {
            if(!flow[x][v]) continue; 
            if(C[v]>C[x]+cost[x][v]) 
            {
                C[v]=C[x]+cost[x][v];
                F[v]=min(F[x],flow[x][v]);
                que[++tl]=v; pre[v]=x;
            }
        }
    }
} 
void Dinic()
{
    memcpy(cost,c,sizeof(c)); memcpy(flow,f,sizeof(f));
    int cash=0,tmp,x;
    while(1)
    {
        bfs(); if(!F[T]) break;
        for(x=T;x!=S;x=pre[x]) 
            flow[pre[x]][x]-=F[T],flow[x][pre[x]]+=F[T];
        cash+=C[T]*F[T];
    }
    printf("%d\n",cash);
}
};

namespace S2{
void bfs()
{
    int x,v;
    memset(C,-0x3f,sizeof(C)); memset(F,0,sizeof(F)); 
    hd=1,tl=0; que[++tl]=S; C[S]=0; F[S]=inf;
    while(hd<=tl)
    {
        x=que[hd++];
        for(v=1;v<=nn;v++)
        {
            if(!flow[x][v]) continue; 
            if(C[v]<C[x]+cost[x][v]) 
            {
                C[v]=C[x]+cost[x][v];
                F[v]=min(F[x],flow[x][v]);
                que[++tl]=v; pre[v]=x;
            }
        }
    }
} 
void Dinic()
{
    memcpy(cost,c,sizeof(c)); memcpy(flow,f,sizeof(f));
    int cash=0,tmp,x;
    while(1)
    {
        bfs(); if(!F[T]) break;
        for(x=T;x!=S;x=pre[x]) 
            flow[pre[x]][x]-=F[T],flow[x][pre[x]]+=F[T];
        cash+=C[T]*F[T];
    }
    printf("%d\n",cash);
}
};


int main()
{
    scanf("%d",&n); nn=n*2+2;
    int i,j,v,ans; S=n+n+1,T=n+n+2;
    for(i=1;i<=n;i++) for(j=1;j<=n;j++) 
        scanf("%d",&c[i][n+j]),c[n+j][i]=-c[i][n+j],f[i][n+j]=1;
    for(i=1;i<=n;i++) f[S][i]=1,f[n+i][T]=1;
    S1::Dinic(); S2::Dinic();
    return 0;
}