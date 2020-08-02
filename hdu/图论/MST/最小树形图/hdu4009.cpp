#include"string.h"
#include"stdio.h"
#include"math.h"
#include"queue"
#define eps 1e-10
#define M 1009
#define inf 100000000
using namespace std;
struct node
{
    int x,y,z;
}p[M];
struct edge
{
    int u,v;
    int w;
}edge[M*M];
int pre[M],id[M],use[M],in[M];
int Fabs(int x)
{
    return x>0?x:-x;
}
int mini_tree(int root,int n,int m)//分别是树根，节点数，边数，序号从1开始
{
    int ans=0;
    int i,u;
    while(1)
    {
        for(i=1;i<=n;i++)
            in[i]=inf;
        for(i=1;i<=m;i++)
        {
            int u=edge[i].u;
            int v=edge[i].v;
            if(edge[i].w<in[v]&&u!=v)
            {
                in[v]=edge[i].w;
                pre[v]=u;
            }
        }//找最小的入边
        for(i=1;i<=n;i++)
        {
            if(i==root)continue;
            ans+=in[i];//把边权加起来
            if(in[i]==inf)//如果存在没有入弧的点则不存在最小树形图
                return -1;
        }
        memset(id,-1,sizeof(id));
        memset(use,-1,sizeof(use));
        int cnt=0;
        for(i=1;i<=n;i++)//枚举每个点，搜索找环
        {
            int v=i;
            while(v!=root&&use[v]!=i&&id[v]==-1)
            {
                use[v]=i;
                v=pre[v];
            }
            if(v!=root&&id[v]==-1)//当找到环的时候缩点编号
            {
                ++cnt;
                id[v]=cnt;
                for(u=pre[v];u!=v;u=pre[u])
                    id[u]=cnt;
            }
        }
        if(cnt==0)//如果没有环结束程序
            break;
        for(i=1;i<=n;i++)//把余下的不在环里的点编号
            if(id[i]==-1)
                id[i]=++cnt;
        for(i=1;i<=m;i++)//建立新的图
        {
            int u=edge[i].u;
            int v=edge[i].v;
            edge[i].u=id[u];
            edge[i].v=id[v];
            if(edge[i].u!=edge[i].v)
                edge[i].w-=in[v];
        }
        n=cnt;//更新节点数和根节点的编号
        root=id[root];
    }
    return ans;
}
int main()
{
    int n,X,Y,Z,i,j;
    while(scanf("%d%d%d%d",&n,&X,&Y,&Z),n||X||Y||Z)
    {
        for(i=1;i<=n;i++)
            scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
        int m=0;
        for(i=1;i<=n;i++)
        {
            int k;
            scanf("%d",&k);
            while(k--)
            {
                scanf("%d",&j);
                if(i==j)continue;
                m++;
                edge[m].u=i;
                edge[m].v=j;
                if(p[j].z>p[i].z)
                    edge[m].w=Z+Y*(Fabs(p[i].x-p[j].x)+Fabs(p[i].y-p[j].y)+Fabs(p[i].z-p[j].z));
                else
                    edge[m].w=Y*(Fabs(p[i].x-p[j].x)+Fabs(p[i].y-p[j].y)+Fabs(p[i].z-p[j].z));
            }
        }
        for(i=1;i<=n;i++)
        {
            m++;
            edge[m].u=n+1;
            edge[m].v=i;
            edge[m].w=p[i].z*X;
        }
        int ans=mini_tree(n+1,n+1,m);
        printf("%d\n",ans);
    }
    return 0;
}