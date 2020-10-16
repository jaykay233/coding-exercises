class Solution {
public:
    int dp[10][1<<10];
    int dfs(vector<int>& nums, int i, bool equal_flag, bool front_zero_flag, int front_state) {
        if (i == nums.size()) return 1;
        if (!equal_flag && !front_zero_flag && dp[i][front_state] != -1) {
            return dp[i][front_state];
        }
        int res = 0;
        for (int j = 0; j <= (equal_flag ? nums[i] : 9); ++j) {
            if (front_state >> j & 1) continue;
            bool ef = equal_flag && j == nums[i];
            bool fzf = front_zero_flag && j == 0;
            int state = fzf ? front_state : (front_state | (1 << j));
            res += dfs(nums, i + 1, ef, fzf, state);
        }
        if(!equal_flag && !front_zero_flag) dp[i][front_state]=res;
        return res;
    }
    int numDupDigitsAtMostN(int N) {
        memset(dp, -1, sizeof(dp));
        vector<int> nums;
        for (int t = N; t > 0; t /= 10) {
            nums.push_back(t % 10);
        }
        reverse(nums.begin(), nums.end());
        return 1 + N - dfs(nums, 0, true, true, 0);
    }
};