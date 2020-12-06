#include <bits/stdc++.h>
using namespace std;
//主要求2个东西
//1.割边
//2.求点双连通里边数是否大于点数，一个点双连通只有一个环的话边数等于点数

const int M = 200010;
const int N = 10010;
 
struct Edge {
    int from, to;
    int next;
} edge[M];
int head[N];
int cnt_edge;
void add_edge(int u, int v)
{
    edge[cnt_edge].from = u;
    edge[cnt_edge].to = v;
    edge[cnt_edge].next = head[u];
    head[u] = cnt_edge++;
}
 
int dfn[N]; int idx;
int low[N];
stack<Edge> stk;
set<int> bcc;
int cut;    // 桥的数量
int ans;    // 冲突边数量
int m, n;
 
void dfs(int u, int pre)
{
    dfn[u] = low[u] = ++idx;
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == pre) continue;
        if (!dfn[v])
        {
            stk.push(edge[i]);
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u])       // 割点
            {
                Edge tmp;
                int cnt = 0;
                bcc.clear();
                do {
                    cnt++;
                    tmp = stk.top();
                    stk.pop();
                    bcc.insert(tmp.from);
                    bcc.insert(tmp.to);
                } while (tmp.from != u || tmp.to != v);
                if (cnt > bcc.size()) ans += cnt;
            }
            if (low[v] > dfn[u]) ++cut;
        }
        else if (dfn[v] < dfn[u])
        {
            stk.push(edge[i]);
            low[u] = min(low[u], dfn[v]);
        }
    }
}
 
void init()
{
    memset(head, -1, sizeof head);
    memset(dfn, 0, sizeof dfn);
    ans = cut = cnt_edge = idx = 0;
}
 
int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        if (n == 0 && m == 0) break;
        int u, v;
        init();
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d", &u, &v);
            add_edge(u, v);
            add_edge(v, u);
        }
        for (int i = 1; i <= n; ++i)
        if (!dfn[i]) dfs(i, -1);
        printf("%d %d\n", cut, ans);
    }
    return 0;
}