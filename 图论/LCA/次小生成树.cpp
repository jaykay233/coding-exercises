#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;
int n,m;
const int N = 100010, M = 300010, INF = 0x3f3f3f3f;
vector<int> dist;

struct Edge
{
    int a, b, w;
    bool used;
    bool operator< (const Edge &t) const
    {
        return w < t.w;
    }
}edge[M];
int p[N];
int h[N], e[M], w[M], ne[M], idx;
int depth[N], fa[N][17], d1[N][17], d2[N][17];
int q[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

LL kruskal()
{
    for (int i = 1; i <= n; i ++ ) p[i] = i;
     
    sort(edge, edge + m);
      

    LL res = 0;
    for (int i = 0; i < m; i ++ )
    {
        int a = find(edge[i].a), b = find(edge[i].b), w = edge[i].w;
        if (a != b)
        {
            p[a] = b;
            res += w;
            edge[i].used = true;
        }
    }
    

    return res;
}

void build()
{
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i ++ )
        if (edge[i].used)
        {
            int a = edge[i].a, b = edge[i].b, w = edge[i].w;
            add(a, b, w), add(b, a, w);
        }
}


void bfs()
{
    memset(depth, 0x3f, sizeof depth);
    depth[0] = 0, depth[1] = 1;
    q[0] = 1;
    int hh = 0, tt = 0;
    while (hh <= tt)
    {
        int t = q[hh ++ ];
        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (depth[j] > depth[t] + 1)
            {
                depth[j] = depth[t] + 1;
                q[ ++ tt] = j;
                fa[j][0] = t;
                d1[j][0] = w[i], d2[j][0] = -INF;
                for (int k = 1; k <= 16; k ++ )
                {
                    int anc = fa[j][k - 1];
                    fa[j][k] = fa[anc][k - 1];
                    int distance[4] = {d1[j][k - 1], d2[j][k - 1], d1[anc][k - 1], d2[anc][k - 1]};
                    d1[j][k] = d2[j][k] = -INF;
                    for (int u = 0; u < 4; u ++ )
                    {
                        int d = distance[u];
                        if (d > d1[j][k]) d2[j][k] = d1[j][k], d1[j][k] = d;
                        else if (d != d1[j][k] && d > d2[j][k]) d2[j][k] = d;
                    }
                }
            }
        }
    }
}


int lca(int a,int b,int q){
    if(depth[a]<depth[b]) swap(a,b);
    dist.clear();
    for(int k = 16;k>=0;k--){
        if(depth[fa[a][k]]>=depth[b]) {
            dist.push_back(d1[a][k]);
            dist.push_back(d2[a][k]);
            a = fa[a][k];
        }
    }
    if(a!=b){
        for(int k = 16;k>=0;k--){
            if(fa[a][k]!=fa[b][k]){
                dist.push_back(d1[a][k]);
                dist.push_back(d2[a][k]);
                dist.push_back(d1[b][k]);
                dist.push_back(d2[b][k]);
                a = fa[a][k];
                b = fa[b][k];
            }
        }
        dist.push_back(d1[a][0]);
        dist.push_back(d1[b][0]);
    }
    
    int dist1 = -INF;
    int dist2 = -INF;
    
    
    for(int i =0;i<dist.size();i++){
        int d = dist[i];
        if(d>dist1) dist1 = d;
        else if(d!=dist1 && d>dist2) dist2 = d; 
    }

    
    if(q>dist1) return q - dist1;
    if(q>dist2) return q - dist2;
    return INF;

}




int main(){
    memset(h,-1,sizeof h);
    cin>>n>>m;
    for(int i =0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        edge[i] = {x,y,z};
    }

    
    long long res = kruskal();

    build();
    bfs();

    long long  sum  = 1e18;
    for(int i =0;i<m;i++){
        if(!edge[i].used){
            int x = edge[i].a;
            int y = edge[i].b;
            int z = edge[i].w;
            sum = min(sum,res+lca(x,y,z));
        }
    }

    
    cout<<sum<<endl;
    
    return 0;
}