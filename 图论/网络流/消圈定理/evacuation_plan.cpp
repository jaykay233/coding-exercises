#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#include <queue>
#include <vector>
#define inf 100000000
#define M 333
using namespace std;
int t,head[M],in[M],vis[M],dis[M],flow[M],pre[M],use[M];
struct Lode
{
    int x,y,val;
} but[M],sht[M];
int Fab(int a)
{
    if(a<0)
        a=-a;
    return a;
}
struct node
{
    int v,val,cost;
    node(int V,int VAL,int COST)
    {
        v=V;
        val=VAL;
        cost=COST;
    }
};
vector<node>edge[M];
int fuck[M],cnt;
int spfa(int s,int n)
{
    queue<int>q;
    memset(in,0,sizeof(in));
    memset(vis,0,sizeof(vis));
    memset(pre,-1,sizeof(pre));
    for(int i=0; i<=n; i++)
        dis[i]=inf;
    dis[s]=0;
    q.push(s);
    vis[s]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=0; i<(int)edge[u].size(); i++)
        {
            int v=edge[u][i].v;
            if(edge[u][i].val&&dis[v]>dis[u]+edge[u][i].cost)
            {
                dis[v]=dis[u]+edge[u][i].cost;
                pre[v]=u;
                if(!vis[v])
                {
                    vis[v]=1;
                    q.push(v);
                    in[v]++;
                    if(in[v]>n)
                    {
                        return v;
                    }
                }
            }
        }
    }
    return 0;
}
int E[M][M],len[M][M];
int main()
{
    int n,m,i,j,k;
    while(scanf("%d%d",&n,&m)!=-1)
    {
        for(i=0; i<=n+m+1; i++)
            edge[i].clear();
        for(i=1; i<=n; i++)
            scanf("%d%d%d",&but[i].x,&but[i].y,&but[i].val);
        for(i=1; i<=m; i++)
            scanf("%d%d%d",&sht[i].x,&sht[i].y,&sht[i].val);
        for(i=1; i<=n; i++)
            for(j=1; j<=m; j++)
                len[i][j]=Fab(but[i].x-sht[j].x)+Fab(but[i].y-sht[j].y)+1;
        memset(flow,0,sizeof(flow));
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                scanf("%d",&E[i][j]);
                edge[i].push_back(node(j+n,inf-E[i][j],len[i][j]));
                edge[j+n].push_back(node(i,E[i][j],-len[i][j]));
                flow[j]+=E[i][j];//到避难所的当前总流量
            }
        }
        for(j=1; j<=m; j++)
        {
            edge[j+n].push_back(node(n+m+1,sht[j].val-flow[j],0));
            edge[n+m+1].push_back(node(j+n,flow[j],0));
        }
        int ans=spfa(m+n+1,n+m+1);
        if(!ans)
        {
            printf("OPTIMAL\n");
            continue;
        }
        for(i=1; i<=m+n; i++)
        {
            memset(use,0,sizeof use);
            use[i] = 1;
            int j = pre[i];
            int flag = 0;
            while(j!=-1){
                use[j] ++;
                cnt = 0;
                if(use[j]>=2){
                    fuck[cnt++] = j;
                    k = pre[j];
                    while(k!=-1 && k!=j){
                        fuck[cnt++] = k;
                        k = pre[k];
                    }
                    fuck[cnt++] = k;
                }
                if(cnt){
                    flag ++;
                    break;
                }
                j = pre[j];
            }
            if(flag) break;
        }
        for(i=cnt-1; i>0; i--)
        {
            if(fuck[i]>=1&&fuck[i]<=n+m&&fuck[i-1]>=1&&fuck[i-1]<=m+n)
            {
                if(fuck[i]<=n&&fuck[i-1]>n)
                    E[fuck[i]][fuck[i-1]-n]++;
                if(fuck[i]>n&&fuck[i-1]<=n)
                    E[fuck[i-1]][fuck[i]-n]--;
            }
        }
        printf("SUBOPTIMAL\n");
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                if(j==1)
                    printf("%d",E[i][j]);
                else
                    printf(" %d",E[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}