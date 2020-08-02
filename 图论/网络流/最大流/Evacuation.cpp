#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
 
int V,X,Y;
char field[13][13];
int dir[4][2]= {{1,0},{-1,0},{0,1},{0,-1}};
vector<int> G[50010];
vector<int> dx,dy; //门的坐标
vector<int> px,py; //人的坐标
int link[50005];
int dist[13][13][13][13];//最近距离
bool vis[50005];
 
void adde_dge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
 
bool dfs(int v)
{
    vis[v]=true;
    for(int i=0; i<G[v].size(); i++)
    {
        int u=G[v][i];
        if(link[u]==-1||!vis[link[u]]&&dfs(link[u]))
        {
            link[v]=u;
            link[u]=v;
            return true;
        }
    }
    return false;
}
 
void bfs(int x,int y,int d[13][13])//计算最短距离
{
    queue<int> qx,qy;
    d[x][y]=0;
    qx.push(x);
    qy.push(y);
    while(!qx.empty())
    {
        x=qx.front();
        qx.pop();
        y=qy.front();
        qy.pop();
        for(int k=0; k<4; k++)
        {
            int x2=x+dir[k][0];
            int y2=y+dir[k][1];
            if(0<=x2&&x2<X&&0<=y2&&y2<Y&&field[x2][y2]=='.'&&d[x2][y2]<0)
            {
                d[x2][y2]=d[x][y]+1;
                qx.push(x2);
                qy.push(y2);
            }
        }
    }
}
 
void solve()
{
    int n=X*Y;
    dx.clear();
    dy.clear();
    px.clear();
    py.clear();
    memset(dist,-1,sizeof(dist));
    for(int x=0; x<X; x++)//计算到各个门的最短距离
        for(int y=0; y<Y; y++)
        {
            if(field[x][y]=='D')
            {
                dx.push_back(x);
                dy.push_back(y);
                bfs(x,y,dist[x][y]); //每个人能到该点的最小距离
            }
            else if(field[x][y]=='.')  //if中的==要注意
            {
                px.push_back(x);
                py.push_back(y);
            }
        }
    //建图
    int d=dx.size(),p=px.size();
    V=X*Y*d+p;
    for(int v=0; v<V; ++v) G[v].clear();
    for(int i=0; i<d; i++)
        for(int j=0; j<p; j++)
            if(dist[dx[i]][dy[i]][px[j]][py[j]]>=0)  //若该人能到达该门
                for(int k=dist[dx[i]][dy[i]][px[j]][py[j]]; k<=n; k++)
                    adde_dge((k-1)*d+i,n*d+j); //该人与不同时间的该门建边
    if(p==0)
    {
        cout<<"0"<<endl;
        return;
    }
    int res=0;
    memset(link,-1,sizeof(link));
    for(int v=0; v<n*d; v++) //枚举门的集合
    {
        memset(vis,0,sizeof(vis));
        if(dfs(v))
            if(++res==p)  //若所有人能逃出
            {
               cout<<(v/d+1)<<endl;;
                return;
            }
    }
    cout<<"impossible"<<endl;
}
 
int main()
{
    int i,j,k,t;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>X>>Y;
        for(i=0; i<X; i++)
            cin>>field[i];
        solve();
    }
}