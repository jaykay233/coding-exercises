#include <bits/stdc++.h>
using namespace std;
const int N = 100010,M = 400010;
int h[N],e[M],ne[M],idx;
int din[N],dout[N];
int type,n,m,cnt;
bool ans[M],used[M];

void add(int a,int b){
    e[idx] = b;ne[idx] = h[a];h[a] = idx++;
}

void dfs(int u)
{
    for (int &i = h[u]; ~i;)
    {
        if (used[i])
        {
            i = ne[i];
            continue;
        }

        used[i] = true;
        if (type == 1) used[i ^ 1] = true;

        int t;

        if (type == 1)
        {
            t = i / 2 + 1;
            if (i & 1) t = -t;
        }
        else t = i + 1;

        int j = e[i];
        i = ne[i];
        dfs(j);

        ans[ ++ cnt] = t;
    }
}


int main()
{
    scanf("%d", &type);
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i ++ )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        if (type == 1) add(b, a);
        din[b] ++ , dout[a] ++ ;
    }

    if (type == 1)
    {
        for (int i = 1; i <= n; i ++ )
            if (din[i] + dout[i] & 1)
            {
                puts("NO");
                return 0;
            }
    }
    else
    {
        for (int i = 1; i <= n; i ++ )
            if (din[i] != dout[i])
            {
                puts("NO");
                return 0;
            }
    }

    for (int i = 1; i <= n; i ++ )
        if (h[i] != -1)
        {
            dfs(i);
            break;
        }

    if (cnt < m)
    {
        puts("NO");
        return 0;
    }

    puts("YES");
    for (int i = cnt; i; i -- ) printf("%d ", ans[i]);
    puts("");

    return 0;
}
