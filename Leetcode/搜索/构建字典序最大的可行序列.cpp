#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(n * 2 - 1, -1);
        vector<bool> vi(n + 1, false);
        dfs(ans, 0, vi);
        return ans;
    }

    bool dfs(vector<int>& ans, int idx, vector<bool>& vi) {
        if (idx == ans.size()) return true;
        if (ans[idx] != -1) return dfs(ans, idx + 1, vi);

        for (int i = (int)vi.size() - 1; i != 0; i--) {
            if (vi[i]) continue;
            if (idx + i >= ans.size() || ans[idx + i] != -1) continue;
            ans[idx] = ans[idx + i] = i;
            vi[i] = true;
            if (dfs(ans, idx + 1, vi)) return true;
            vi[i] = false;
            ans[idx] = ans[idx + i] = -1;
        }

        if (!vi[1]) {
            ans[idx] = 1;
            vi[1] = true;
            if (dfs(ans, idx + 1, vi)) return true;
            vi[1] = false;
            ans[idx] = -1;
        }
        return false;
    }
};