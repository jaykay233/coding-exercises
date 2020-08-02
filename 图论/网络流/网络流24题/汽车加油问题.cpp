#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 50;
const int M = 1e6;
const int inf = 0x3f3f3f3f;
 
int NXT[M], TO[M], V[M];
int DIS[N], VIS[N], HD[N];
int MAP[205][205];
int ss, tt, sz, k, n, m, a, b, c, tot;
queue<int> q;
 
int mk(int x, int y, int z) {
    return z * n * n + (x - 1) * n + y;
}
 
void add(int x, int y, int z) {
    TO[sz] = y; V[sz] = z;
    NXT[sz] = HD[x]; HD[x] = sz++;
}
 
int spfa() {
    memset(DIS, 0x3f, sizeof (DIS));
    DIS[ss] = 0;
    q.push(ss);
    while (!q.empty()) {
        int u = q.front();
        VIS[u] = 0;
        q.pop();
        for (int i = HD[u]; i != -1; i = NXT[i]) {
            int v = TO[i];
            if (DIS[v] > DIS[u] + V[i]) {
                DIS[v] = DIS[u] + V[i];
                if (!VIS[v]) {
                    VIS[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return DIS[tt];
}
 
int main() {
    memset(HD, -1, sizeof (HD));
    scanf("%d%d%d%d%d", &n, &k, &a, &b, &c);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            scanf("%d", &MAP[i][j]);
    tt = 200010;
    for (int x = 1; x <= n; ++x) {
        for (int y = 1; y <= n; ++y) {
            for (int i = k; i >= 0; --i) {
                tot = mk(x, y, i);
                if (x == 1 && y == 1 && i == k)
                    ss = tot;
                if (x == n && y == n)
                    add(tot, tt, 0);
                if (i != k)
                    if (MAP[x][y]) add(tot, mk(x, y, k), a);
                    else add(tot, mk(x, y, k), a + c);  
                if (i != 0) {
                    if (MAP[x][y] && i != k) continue; //注意避开这种情况
                    if (x != 1)
                        add(tot, mk(x - 1, y, i - 1), b);
                    if (y != 1)
                        add(tot, mk(x, y - 1, i - 1), b);
                    if (x != n)
                        add(tot, mk(x + 1, y, i - 1), 0);
                    if (y != n)
                        add(tot, mk(x, y + 1, i - 1), 0);
                }
            }
        }
    }
    printf("%d\n", spfa());
    return 0;
}