#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
   struct Vertex {
      int i;
      int j;
      int val;
      bool operator<(const Vertex& rhs) const { return val < rhs.val; }
   };

   int maximumMinimumPath(vector<vector<int>>& A) {
      const vector<pair<int, int>> dirs = { {0,1},{0,-1},{-1,0},{1,0} };
      const int n = A.size(), m = A[0].size();
      auto vv = vector(n, vector<int>(m, -1));
      priority_queue<Vertex> q;
      q.push({ 0,0,A[0][0] });
      while (!q.empty()) {
         const auto [i, j, val] = q.top(); q.pop();         
         for (auto [dx, dy] : dirs) {
            int x = i + dx, y = j + dy;
            if (x < 0 || x >= n || y < 0 || y >= m || vv[x][y] != -1) continue;
            vv[x][y] = min(val, A[x][y]);
            if (x == n - 1 && y == m - 1) return vv[x][y];
            q.push({ x, y, vv[x][y] });
         }
      }
      return -1;
   }
};
