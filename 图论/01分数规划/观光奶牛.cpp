#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N = 1010;
const int M = 5010;
int h[N],w[M],ne[M],e[M],f[N];
int idx =0 ;
bool st[N];
double dist[N];
int q[N];
int cnt[N];

void add(int a,int b,int c){
    e[idx] = b;w[idx] = c;ne[idx] = h[a];h[a] = idx++;
}



bool check(double mid)
{
    memset(dist, 0, sizeof dist);
    memset(st, 0, sizeof st);
    memset(cnt, 0, sizeof cnt);

    int hh = 0, tt = 0;
    for (int i = 1; i <= n; i ++ )
    {
        q[tt ++ ] = i;
        st[i] = true;
    }

    while (hh != tt)
    {
        int t = q[hh ++ ];
        if (hh == N) hh = 0;
        st[t] = false;

        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dist[j] < dist[t] + f[t] - mid * w[i])
            {
                dist[j] = dist[t] + f[t] - mid * w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n) return true;
                if (!st[j])
                {
                    q[tt ++ ] = j;
                    if (tt == N) tt = 0;
                    st[j] = true;
                }
            }
        }
    }

    return false;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> f[i];

    memset(h, -1, sizeof h);
    for (int j = 0; j < m; j ++ )
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    double l = 0, r = 1e6;
    while (r - l > 1e-4)
    {
        double mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }

    printf("%.2lf\n", l);

    return 0;
}
