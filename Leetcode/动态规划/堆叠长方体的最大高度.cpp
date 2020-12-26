class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        for (auto& cubic: cuboids) {
            sort(cubic.begin(), cubic.end());
        }
        
        sort(cuboids.begin(), cuboids.end(), [](const auto& u, const auto& v) {
            return pair(u[2], u[0] + u[1]) < pair(v[2], v[0] + v[1]);
        });
        
        vector<int> f(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (cuboids[j][0] <= cuboids[i][0] && cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2]) {
                    f[i] = max(f[i], f[j]);
                }
            }
            f[i] += cuboids[i][2];
        }
        return *max_element(f.begin(), f.end());
    }
};
