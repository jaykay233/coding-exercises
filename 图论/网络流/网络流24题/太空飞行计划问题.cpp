#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

const int MAXN = 1000005;
const int INF = 1e9;

struct Edge {
    int to, cap, rev;
    Edge(int to, int cap, int rev): to(to), cap(cap), rev(rev) {}
};

std::vector<Edge> vec[MAXN];
std::queue<int> que;
int level[MAXN], pre[MAXN];

inline void addedge(int u, int v, int cap) {
    vec[u].push_back(Edge(v, cap, vec[v].size()));
    vec[v].push_back(Edge(u, 0, vec[u].size() - 1));
}

// Dinic 

inline bool bfs(int s, int t) {
    memset(level, -1, sizeof level);
    level[s] = 0;
    que.push(s);
    while(!que.empty()) {
        int u = que.front();
        que.pop();
        for(int i = 0; i < vec[u].size(); i++) {
            int v = vec[u][i].to;
            if(level[v] == -1 && vec[u][i].cap > 0) {
                level[v] = level[u] + 1;
                que.push(v);
            }
        }
    }
    return level[t] != -1;
}

inline int dfs(int u, int t, int left) {
    if(u == t) return left;
    for(int i = 0; i < vec[u].size(); i++) {
        int v = vec[u][i].to;
        if(vec[u][i].cap > 0 && level[v] == level[u] + 1) {
            int d = dfs(v, t, std::min(left, vec[u][i].cap));
            if(d > 0) {
                vec[u][i].cap -= d;
                vec[v][vec[u][i].rev].cap += d;
                pre[u >> 1] = v >> 1;
                return d;
            }
        }
    }
    return 0;
}

inline int max_flow(int s, int t) {
    int flow = 0;
    while(bfs(s, t)) {
        int f;
        while((f = dfs(s, t, INF)) > 0) {
            flow += f;
        }
    }
    return flow;
}

int m, n, t, S, T, ans = 0;
char str[10005];

int main() {
    scanf("%d%d", &m, &n);
    S = n + m + 1;
    T = S + 1;
    for(int i = 1; i <= m; i++) {
        scanf("%d", &t);
        ans += t;
        addedge(S, i, t);
        // 洛谷数据太坑 
        memset(str, 0, sizeof str);
        int now = 0;
        std::cin.getline(str, 10000);
        while(sscanf(str + now, "%d", &t) == 1) {
            addedge(i, t + m, INF);
            if(t == 0) {
                now++;
            } else {
                while(t) {
                    t /= 10;
                    now++;
                }
            } 
            now++;
        }
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &t);
        addedge(i + m, T, t);
    }
    ans -= max_flow(S, T);
    for(int i = 1; i <= m; i++) {
        if(level[i] != -1) printf("%d ", i);
    }
    printf("\n");
    for(int i = 1; i <= n; i++) {
        if(level[m + i] != -1) printf("%d ", i);
    }
    printf("\n%d", ans);
    return 0; 
}