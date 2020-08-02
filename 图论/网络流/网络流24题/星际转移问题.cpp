// 分层图网络流问题，枚举答案，构造网络流判定。

// 【建模方法】

// 首先判断从地球到月球是否存在一条路线，如果不存在那么无解，否则把每个太空站按照每天拆分成d个点，<i,d><i,d>表示第i个站第d天。建立附加源S汇T，顺序枚举答案Day。

// 1、对于第Day天，从S到<0,Day><0,Day>连接一条容量为无穷大的有向边。
// 2、从<−1,Day><−1,Day>到T连接一条容量为无穷大的有向边。
// 3、对于第i个太空船，设第Day-1天在a处，第Day天在b处，从<a,Day−1><a,Day−1>到<b,Day><b,Day>连接一条容量为该太空船容量的有向边。
// 4、对于第i个太空站，从<i,Day−1<i,Day−1>到<i,Day><i,Day>连接一条容量为无穷大的有向边。
// 5、求当前网络最大流，如果最大流量大于等于地球上人数K，停止枚举，当前Day值就是答案。

// 【建模分析】

// 我们把网络优化问题转化为枚举答案+可行性判定问题。枚举天数，按天数把图分层，因为乘船每坐一站天数都要增加一，把太空船航线抽象成图中的一条边，跨图的两层。由于太空船容量有限，边上也要加上容量限制。除了坐船以外，人还可以在某个空间站等待下一班太空船的到来，所以每个点要与下一层同一点连接一条容量为无穷的边。这样在层限制的图上求出的网络最大流就是在当前天数以内能够从地面到月球的最多的人数，该人数随天数递增不递减，存在单调性。所以可以枚举答案或二分答案，用网络流判定。网络流判定问题更适合枚举答案，而不是二分，因为新增一些点和边只需要在原有的基础上增广，不必重新求网络流。

#pragma comment(linker, "/STACK:102400000,102400000")
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define MOD 1e9+7
#define lson l,mid,root<<1
#define rson mid+1,r,root<<1|1
#define DBN1(a)           cerr<<#a<<"="<<(a)<<"\n"
#define DBN2(a,b)         cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"
#define DBN3(a,b,c)       cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
#define DBN4(a,b,c,d)     cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"
#define DBN5(a,b,c,d,e)   cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<"\n"
#define DBN6(a,b,c,d,e,f) cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<", "<<#f<<"="<<(f)<<"\n"
using namespace std;
typedef long long ll;
const int maxn=500000+5;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
template<typename T>
inline T read(T&x){
    x=0;int _f=0;char ch=getchar();
    while(ch<'0'||ch>'9')_f|=(ch=='-'),ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x=_f?-x:x;
}
struct Edge{
    int from,to,cap,flow;
    Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f){}
};
struct Dinic{
    int n,m,s,t;
    vector<Edge>edges;
    vector<int>G[maxn];
    bool vis[maxn];
    int d[maxn];
    int cur[maxn];
    int flow;

    void init(int n){
        for (int i=0;i<n;i++) G[i].clear();
        edges.clear();
        flow=0;
    }

    void AddEdge(int from,int to,int cap){
        edges.push_back(Edge(from,to,cap,0));
        edges.push_back(Edge(to,from,0,0));
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    bool BFS(){
        memset(vis,0,sizeof(vis));
        queue<int>Q;
        Q.push(s);
        d[s]=0;
        vis[s]=1;
        while (!Q.empty()){
            int x=Q.front();Q.pop();
            for (int i=0;i<(int)G[x].size();i++){
                Edge& e=edges[G[x][i]];
                if (!vis[e.to] && e.cap>e.flow){
                    vis[e.to]=1;
                    d[e.to]=d[x]+1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }

    int DFS(int x,int a){
        if (x==t || a==0) return a;
        int flow=0,f;
        for (int& i=cur[x];i<(int)G[x].size();i++){
            Edge& e=edges[G[x][i]];
            if (d[x]+1==d[e.to] && (f=DFS(e.to,min(a,e.cap-e.flow)))>0){
                e.flow+=f;
                edges[G[x][i]^1].flow-=f;
                flow+=f;
                a-=f;
                if (a==0) break;
            }
        }
        return flow;
    }

    int Maxflow(int s,int t){
        this->s=s;this->t=t;
        while (BFS()){
            memset(cur,0,sizeof(cur));
            flow+=DFS(s,INF);
        }
        return flow;
    }
}A;
int n,m,k,kkk;
int h[20],r[20][25];
vector<int>GG[25];
bool vis[25];
inline int f(int d){return kkk*d;}
int main(){
    read(n),read(m),read(k);
    for (int i=1;i<=m;i++){
        read(h[i]),read(r[i][0]);
        for (int j=1;j<=r[i][0];j++){
            int x;
            read(x);
            if (x==0) r[i][j]=n+1;
            else if (x==-1) r[i][j]=n+2;
            else r[i][j]=x;
            if (j!=1) GG[r[i][j-1]].push_back(r[i][j]);
            if (j==r[i][0] && r[i][0]!=1) GG[r[i][j]].push_back(r[i][1]);
        }
    }
    queue<int>Q;
    Q.push(n+1);
    vis[n+1]=true;
    bool flag=false;
    while (!Q.empty()){
        int cur=Q.front();Q.pop();
        if (cur==n+2){
            flag=true;
            break;
        }
        for (int i=0;i<(int)GG[cur].size();i++){
            int v=GG[cur][i];
            if (!vis[v]){
                Q.push(v);
                vis[v]=true;
            }
        }
    }
    if (!flag) return puts("0")*0;
    int s=0,t=1105;
    A.init(t+1);
    A.AddEdge(s,n+1,INF),A.AddEdge(n+2,t,INF);
    kkk=n+2;
    for (int d=1;;d++){
        A.AddEdge(s,n+1+f(d),INF),A.AddEdge(n+2+f(d),t,INF);
        for (int i=1;i<=n;i++){
            A.AddEdge(i+f(d-1),i+f(d),INF);
        }
        for (int i=1;i<=m;i++){
            A.AddEdge(r[i][(d-1)%r[i][0]+1]+f(d-1),r[i][d%r[i][0]+1]+f(d),h[i]);
        }
        if (A.Maxflow(s,t)>=k){
            return printf("%d\n",d)*0;
        }
    }
}
