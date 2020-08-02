//给你n个点，m条无向边，每条边都有长度d和花费p，
//给你起点s终点t，要求输出起点到终点的最短距离及其花费，
//如果最短距离有多条路线，则输出花费最少的。

//输入n,m，点的编号是1~n,然后是m行，每行4个数 a,b,d,p，
//表示a和b之间有一条边，且其长度为d，花费为p。最后一行是两个数 s,t;
//起点s，终点。n和m为0时输入结束。
//(1<n<=1000, 0<m<100000, s != t)

#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#include <utility>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
#define maxn 1210
#define LL int
const LL  INF = 1e9+1000;
 
int mp[maxn][maxn];
int money[maxn][maxn];
LL dis[maxn];
LL mny[maxn];
int n,m;
void init()
{
    for(int i = 1; i <= n; i++) fill(money[i],money[i]+n+1,INF), fill(mp[i],mp[i]+n+1,INF);
    fill(dis,dis+n+1,INF);
    fill(mny,mny+n+1,INF);
 
}
void SPFA(int s)
{
    queue<int> Q;
    dis[s] = 0;
    mny[s] = 0;
    Q.push(s);
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(int i = 1;i <= n; i++)
        {
            if(dis[i] > mp[u][i] + dis[u])
            { 
                dis[i] = mp[u][i] + dis[u];
                mny[i] = money[u][i] + mny[u];
                Q.push(i);
            }
            else if(dis[i] ==  mp[u][i] + dis[u])
            {
                mny[i] = min(mny[i],money[u][i] + mny[u]);
 
            }
        }
    }
    
}
int  main()
{
#ifdef xxz
    freopen("in.txt","r",stdin);
#endif // xxz
 
    while(~scanf("%d%d",&n,&m))
    {
        if( n == 0 && m == 0) break;
        init();
        for(int i = 1; i <= m; i++)
        {
             int a,b ,c, d;
             scanf("%d%d%d%d",&a,&b,&c,&d);
             if(c < mp[a][b])
             {
                 mp[a][b] = mp[b][a] = c;
                 money[a][b] = money[b][a] = d;
             }
             else if(c == mp[a][b])
             {
                if(d < money[a][b]) money[a][b] = money[b][a] = d;
             }
 
        }
        int st,ed;
        scanf("%d%d",&st,&ed);
        SPFA(st);
        printf("%d %d\n",dis[ed],mny[ed]);
    }
    return 0;
}