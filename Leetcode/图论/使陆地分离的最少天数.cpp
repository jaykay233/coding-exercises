const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

class Solution {
    int idx = 0;
    bool found = false;
    vector<int> p, sz, dfn, low;
    vector<vector<int>> adj;
    void tarjan(int u, int p) {
        dfn[u] = low[u] = ++idx;
        int children = 0;
        for (int v : adj[u]) {
            if (!dfn[v]) {
                children++;
                tarjan(v, u);
                low[u] = min(low[u], low[v]);
                if (p == -1 && children >= 2)
                    found = true;
                else if (p != -1 && low[v] >= dfn[u])
                    found = true;
            }
            else if (v != p)
                low[u] = min(low[u], dfn[v]);
        }
    }
    
    int find(int u) {
        return p[u] == u ? u : p[u] = find(p[u]);
    }
    
    void connect(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv)
            return;
        if (sz[pu] >= sz[pv]) {
            p[pv] = pu;
            sz[pu] += sz[pv];
        } else {
            p[pu] = pv;
            sz[pv] += sz[pu];
        }
    }
    
public:
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int N = n * m;
        p = vector<int>(N, -1);
        sz = vector<int>(N, 1);
        int ans = N;
        adj = vector<vector<int>>(N);
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < m; ++j) {
                if (!grid[i][j])
                    continue;
                int u = i * m + j;
                if (p[u] == -1)
                    p[u] = u;
                int cnt = 0;
                for (int k = 0; k < 4; ++k) {
                    int ni = i + dy[k], nj = j + dx[k];
                    if (ni < 0 || ni >= n || nj < 0 || nj >= m || !grid[ni][nj])
                        continue;
                    int v = ni * m + nj;
                    cnt++;
                    if (p[v] == -1)
                        p[v] = v;
                    connect(u, v);
                    adj[u].emplace_back(v);
                    adj[v].emplace_back(u);
                }
                ans = min(ans, cnt);
            }
        int components = 0;
        for (int i = 0; i < N; ++i) {
            if (p[i] != -1 && i == find(i))
                components++;
        }
        if (components >= 2 || components == 0)
            return 0;
        
        for (int i = 0; i < N; ++i) {
            if (p[i] != -1) {
                if (sz[find(i)] == 1)
                    return 1;
                dfn = vector<int>(N);
                low = vector<int>(N);
                tarjan(i, -1);
                break;
            }
        }
        
        return found ? 1 : 2;
    }
};