#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=109;
int low[maxn],num[maxn];//分别保存dfs树上结点能到达的最浅深度和dfs的访问顺序
bool iscut[maxn];//记录是否是割点
vector<int>G[maxn];//存边
int dfn;//记录递归的顺序，用于给num赋值 
int ans=0;//ans记录割点的数量 
int n;
void tarjan(int u,int fa)//参数分别是当前搜索的结点以及其父结点 
{
    low[u]=num[u]=++dfn;//设置dfs的访问顺序，u是dfs访问的第一个点 
    int child=0;//u的子树的数量
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(!num[v])//v点没有进入过dfs树，也就是没有访问过 
        {
            child++;
            tarjan(v,u);
            low[u]=min(low[u],low[v]);//low[i]的意义是点i所能到的dfs深度最浅的值，father结点由child结点来更新
            if(low[v]>=num[u]&&u!=1)//注意要判断u不是根节点，因为定理中是分为非根节点以及根节点进行讨论的，根节点根节点最后讨论 
            {
                iscut[u]=1; 
            } 
        }
//        else low[u]=min(low[u],num[v]);
        else if(num[v]<num[u]&&v!=fa)// fa也是u的邻居，在之前已经访问过；
        //处理回退边 ,u的子节点可以不通过u访问u以上的结点 
        {
            low[u]=min(low[u],num[v]); 
        }
    }
    if(u==1&&child>=2)
    {
        iscut[u]=1;//根结点有两个或以上的独立子树 
    } 
}
int main()
{
    while(scanf("%d",&n)&&n)
    {
        int t,k;
        for(int i=1;i<=n;i++)G[i].clear();
        memset(iscut,0,sizeof(iscut));
        memset(low,0,sizeof(low));
        memset(num,0,sizeof(num));
        ans=0;
        dfn=0;
        while(scanf("%d",&t)==1&&t)
        {
            while(getchar()!='\n')
            {
                scanf("%d",&k);
                G[t].push_back(k);
                G[k].push_back(t);
            }
        }
        tarjan(1,-1);
        for(int i=1;i<=n;i++)ans+=iscut[i];//扫描割点的数量
        printf("%d\n",ans); 
    }
} 