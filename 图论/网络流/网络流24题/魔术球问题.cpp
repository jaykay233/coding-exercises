#include<bits/stdc++.h>
#define N 3250
using namespace std;

typedef struct
{
    int v;
    long long flow;
}ss;
ss edg[N*N];
vector<int>edges[N];
int now_edges=0;
int fl[N][N];

void init()
{
    for(int i=0;i<N;i++)edges[i].clear();
    now_edges=0;
}

void addedge(int u,int v,long long flow)
{
    fl[u][v]+=flow;
    edges[u].push_back(now_edges);
    edg[now_edges++]=(ss){v,flow};
    edges[v].push_back(now_edges);
    edg[now_edges++]=(ss){u,0};
}

int dis[N],S,T;

bool bfs()
{
    queue<int>q;
    q.push(S);
    memset(dis,0,sizeof(dis));
    dis[S]=1;
    
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        
        int Size=edges[now].size();
        for(int i=0;i<Size;i++)
        {
            ss e=edg[edges[now][i]];
            if(e.flow>0&&dis[e.v]==0)
            {
                dis[e.v]=dis[now]+1;
                q.push(e.v);
            }
        }
    }
    if(dis[T]==0)return 0;
    return 1;
}

int current[N];

long long dfs(int now,long long maxflow)
{
    if(now==T)return maxflow;
    
    int Size=edges[now].size();
    for(int i=current[now];i<Size;i++)
    {
        current[now]=i;
        ss &e=edg[edges[now][i]];
        if(e.flow>0&&dis[e.v]==dis[now]+1)
        {
            long long Flow=dfs(e.v,min(maxflow,e.flow));
            if(Flow!=0)
            {
                fl[now][e.v]-=Flow;
                fl[e.v][now]+=Flow;
                
                e.flow-=Flow;
                edg[edges[now][i]^1].flow+=Flow;
                return Flow;
            
            }
            
        }
        
    
    }
    return 0;
}

long long dinic()
{
     long long ans=0,flow;
    while(bfs())
    {
        memset(current,0,sizeof(current));
        while(flow=dfs(S,LLONG_MAX/2))ans+=flow;
    
    }
    return ans;
}

int f(int n)  //返回球数是n的时候的最小路径覆盖数 
{
    init();
    
    S=2*n+1;
    T=2*n+2;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        if((int)sqrt(i+j)*(int)sqrt(i+j)==(i+j))addedge(2*i-1,2*j,1);    
        
        addedge(S,2*i-1,1);
        addedge(2*i,T,1);
    }
    
    return n-dinic();
}

int vis[N]={0};

void ff(int x,int ans) //dfs寻找每条路径上的点，由于题目的特殊性可以从小到大按顺序寻找 
{
    printf("%d ",x);
    vis[x]=1;
    
    for(int i=x+1;i<=ans;i++)
    if(fl[i*2][x*2-1])
    {
        ff(i,ans);
        break;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    
    int Left=1,Right=1600,ans=1;
    
    while(Left<=Right)
    {
        int mid=(Left+Right)/2;
        
        if(f(mid)<=n)
        {
            ans=mid;
            Left=mid+1;
        }
        else Right=mid-1;
    
    
    }
    printf("%d\n",ans);
    
    for(int i=1;i<=ans;i++)
    {
        if(!vis[i])ff(i,ans),printf("\n");;
        
    }
    
    
    return 0;
}