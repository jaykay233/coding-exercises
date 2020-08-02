#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
const int MAXN = 1e3+5;
const double eps = 1e-9;
const double INF = 1e15;
 
struct Village
{
    int x, y;
    int altitude;
}v[MAXN];
 
int n;
bool vis[MAXN];
double a[MAXN][MAXN], b[MAXN][MAXN];
double w[MAXN][MAXN];
double d[MAXN];
int par[MAXN];
 
 
void input()
{
    for(int i = 1;i <= n; i++)
    {
        cin>> v[i].x ;
        cin>> v[i].y ;
        cin>> v[i].altitude;
    }
    for(int i = 1;i <= n; i++)
        for(int j = i+1;j <= n; j++)
        {
            a[i][j] = a[j][i] = abs(v[i].altitude-v[j].altitude);
            b[i][j] = b[j][i] = sqrt(1.0*(v[i].x-v[j].x)*(v[i].x-v[j].x) + 1.0*(v[i].y-v[j].y)*(v[i].y-v[j].y));
        }
}
 
double Prime()
{
    memset(vis, false, sizeof(vis));
    for(int i = 1; i<=n; i++)
        d[i] = INF;
 
    double t1 = 0, t2 = 0;
    d[1] = 0;
    for(int i = 1;i <= n; i++)
    {
        int u;
        double minv = INF;
        for(int j = 1;j <= n; j++)
        {
            if(!vis[j] && d[j] < minv)
                u = j, minv = d[j];
        }
        if(u == -1) break;
        vis[u] = true;
        
        for(int j = 1;j <= n; j++)
        {
            if(!vis[j] && w[u][j] < d[j])
            {
                d[j] = w[u][j];
                par[j] = u;
            }
        }
        if(u == 1) continue;
        t1 += a[par[u]][u];
        t2 += b[par[u]][u];
    }
    return t1/t2;
}
    
double check(double mid)
{
    for(int i = 1;i <= n; i++)
        for(int j = i+1;j <= n; j++)
            w[j][i] = w[i][j] = a[i][j] - mid*b[i][j];
    return Prime();
}
 
void solve()
{
    double a = 0, b;
    while(true)
    {
        b = check(a);
        if(fabs(a-b) < eps) break;
        a = b;
    }
    printf("%.3f\n", b);
}
    
int main()
{
    while(cin>>n && n)
    {
        input();
        solve();
    }
    return 0;
}
