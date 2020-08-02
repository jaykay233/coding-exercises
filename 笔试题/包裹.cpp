//最大值最小 二分
//二分k
//从所有1出发，bfs k层
//包含剩下的点
#include <bits/stdc++.h>
using namespace std;

const int N = 255;

int n, m;
string g[N];
int dist[N][N];

void bfs(int k)
{
    queue<pair<int, int>> q;
    memset(dist, -1, sizeof dist);
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            if (g[i][j] == '1')
            {
                dist[i][j] = 0;
                q.push({i, j});
            }

    int dx[4] = {-1, 0, 1, 0, }, dy[4] = {0, 1, 0, -1};
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        int x = t.first, y = t.second;
        int distance = dist[x][y];
        if (distance == k) continue;
        for (int i = 0; i < 4; i ++ )
        {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m && dist[a][b] == -1)
            {
                dist[a][b] = distance + 1;
                q.push({a, b});
            }
        }
    }
}

bool check(int k)
{
    bfs(k);

    int min_sum = INT_MAX, max_sum = INT_MIN;
    int min_sub = INT_MAX, max_sub = INT_MIN;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            if (dist[i][j] == -1)
            {
                min_sum = min(min_sum, i + j);
                max_sum = max(max_sum, i + j);
                min_sub = min(min_sub, i - j);
                max_sub = max(max_sub, i - j);
            }

    if (min_sum == INT_MAX) return true;

    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            if (g[i][j] == '0')
            {
                int sum = max(abs(i + j - min_sum), abs(i + j - max_sum));
                int sub = max(abs(i - j - min_sub), abs(i - j - max_sub));
                if (max(sum, sub) <= k) return true;
            }

    return false;
}

int main()
{
    int T;
    cin >> T;
    for (int C = 1; C <= T; C ++ )
    {
        cin >> n >> m;
        for (int i = 0; i < n; i ++ ) cin >> g[i];

        int l = 0, r = n + m;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }

        printf("Case #%d: %d\n", C, r);
    }

    return 0;
}
