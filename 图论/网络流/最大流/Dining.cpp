#include <cstdio>
#include <cstring>

#include <algorithm>
#include <queue>

typedef long long LL;

inline char fgc() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF 
        : *p1++;
}

inline LL readint() {
    register LL res = 0, neg = 1;
    register char c = fgc();
    while(c < '0' || c > '9') {
        if(c == '-') neg = -1;
        c = fgc();
    }
    while(c >= '0' && c <= '9') {
        res = res * 10 + c - '0';
        c = fgc();
    }
    return res * neg;
}

const int MAXN = 405, MAXM = 100005, INF = 1e9;

struct Edge {
    int to, cap, nxt;
} gra[MAXM << 1];
int head[MAXN], tot;

inline void addedge(int u, int v, int cap) {
    gra[tot] = Edge {v, cap, head[u]}; head[u] = tot++;
    gra[tot] = Edge {u, 0, head[v]}; head[v] = tot++;
}

int level[MAXN];
std::queue<int> que;

inline bool bfs(int s, int t) {
    memset(level, -1, sizeof(level));
    level[s] = 0; que.push(s);
    while(!que.empty()) {
        int u = que.front(); que.pop();
        for(int i = head[u]; ~i; i = gra[i].nxt) {
            int v = gra[i].to;
            if(gra[i].cap > 0 && level[v] == -1) {
                level[v] = level[u] + 1;
                que.push(v);
            }
        }
    }
    return level[t] != -1;
}

int cur[MAXN];
bool vis[MAXN];

inline int dfs(int u, int t, int left) {
    if(u == t || !left) 
        return left;
    int flow = 0; vis[u] = true;
    for(int &i = cur[u]; ~i; i = gra[i].nxt) {
        int v = gra[i].to;
        if(gra[i].cap > 0 && !vis[v] && level[v] == level[u] + 1) {
            int d = dfs(v, t, std::min(left, gra[i].cap));
            if(d > 0) {
                left -= d; flow += d;
                gra[i].cap -= d; gra[i ^ 1].cap += d;
                if(!left) {
                    level[u] = -1;
                    return flow;
                }
            }
        }
    }
    return flow;
}

inline int dinic(int s, int t) {
    int flow = 0;
    while(bfs(s, t)) {
        memset(vis, 0, sizeof(vis));
        memcpy(cur, head, sizeof(head));
        int f;
        while(f = dfs(s, t, INF)) {
            flow += f;
        }
    }
    return flow;
}

int n, f, d, fi, di, t, S, T;

// 1~n n+1~2n cow
// 2n+1~2n+f food
// 2n+f+1~2n+f+d drink

int main() {
    memset(head, -1, sizeof(head));
    n = readint(); f = readint(); d = readint();
    S = 2 * n + f + d + 1; T = S + 1;
    for(int i = 1; i <= n; i++) {
        addedge(i, i + n, 1);
    }
    for(int i = 1; i <= f; i++) {
        addedge(S, 2 * n + i, 1);
    }
    for(int i = 1; i <= d; i++) {
        addedge(2 * n + f + i, T, 1);
    }
    for(int i = 1; i <= n; i++) {
        fi = readint(); di = readint();
        while(fi--) {
            t = readint();
            addedge(2 * n + t, i, 1);
        }
        while(di--) {
            t = readint();
            addedge(i + n, 2 * n + f + t, 1);
        }
    }
    printf("%d", dinic(S, T));
    return 0;
}