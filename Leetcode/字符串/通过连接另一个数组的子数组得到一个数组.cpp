class Solution {
public:
    int kmp(vector<int> &s, int &index, vector<int> &t) {
        int m = s.size(), n = t.size();
        vector<int> ne(n, -1);
        for (int i = 1, j = -1; i < n; i++) {
            while (j >= 0 && t[i] != t[j + 1]) j = ne[j];
            if (t[i] == t[j + 1]) j++;
            ne[i] = j;
        }
        for (int i = index, j = -1; i < m; i++) {
            while (j >= 0 && s[i] != t[j + 1]) j = ne[j];
            if (s[i] == t[j + 1]) j++;
            if (j == n - 1) {
                index = i + 1;
                return i - j;
            }
        }
        return -1;
    }

    bool canChoose(vector<vector<int>> &groups, vector<int> &nums) {
        int index = 0;
        for (auto &g : groups) {
            if (kmp(nums, index, g) == -1) return false;
        }
        return true;
    }
};
