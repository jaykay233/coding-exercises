#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e5 + 10;
int n, m, s, t, h[N], cnt, dis[N], inq[N], pre[N], last[N], flow[N];
struct node {
    int v, w, c, nt;
} no[N];
void add(int u, int v, int w, int c) {
    no[cnt] = node{v, w, c, h[u]};
    h[u] = cnt++;
    no[cnt] = node{u, 0, -c, h[v]};
    h[v] = cnt++;
}
int spfa() {
    memset(inq, 0, sizeof inq);
    memset(dis, INF, sizeof dis);
    dis[s] = 0, inq[s] = 1, flow[s] = INF;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int u = q.front();
        q.pop(), inq[u] = 0;
        for(int i = h[u]; ~i; i = no[i].nt) {
            int v = no[i].v;
            if(no[i].w > 0 && dis[v] > dis[u] + no[i].c) {
                dis[v] = dis[u] + no[i].c;
                pre[v] = u, last[v] = i;
                flow[v] = min(flow[u], no[i].w);
                if(!inq[v])
                    inq[v] = 1, q.push(v);
            }
        }
    }
    return dis[t] != INF;
}
ll mcmf() {
    ll ans = 0;
    while(spfa()) {
        for(int i = t; i != s; i = pre[i]) {
            no[last[i]].w -= flow[t];
            no[last[i] ^ 1].w += flow[t];
        }
        ans += 1ll * flow[t] * dis[t];
    }
    return ans;
}
int a, b, P, Q;
int co(int x, int y) {
    return (x - 1) * Q + y;
}

//点权转化成边权

int main() {
    memset(h, -1, sizeof h);
    scanf("%d%d%d%d", &a, &b, &P, &Q);
    P++, Q++;
    t = 1000;
    for(int x, i = 1; i <= P; i++)
        for(int j = 1; j < Q; j++) {
            scanf("%d", &x);
            add(co(i, j), co(i, j) + 1, 1, -x);
            add(co(i, j), co(i, j) + 1, INF, 0);
        }
    for(int x, j = 1; j <= Q; j++)
        for(int i = 1; i < P; i++) {
            scanf("%d", &x);
            add(co(i, j), co(i, j) + Q, 1, -x);
            add(co(i, j), co(i, j) + Q, INF, 0);
        }
    for(int k, x, y, i = 1; i <= a; i++) {
        scanf("%d%d%d", &k, &x, &y);
        x++, y++;
        add(s, co(x, y), k, 0);
    }
    for(int k, x, y, i = 1; i <= b; i++) {
        scanf("%d%d%d", &k, &x, &y);
        x++, y++;
        add(co(x, y), t, k, 0);
    }
    printf("%d\n", -mcmf());
    return 0;
}