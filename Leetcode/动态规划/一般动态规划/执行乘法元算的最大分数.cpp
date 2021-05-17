class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(), m = multipliers.size();
        vector<vector<int>> dp(1000+5,vector<int>(1000+5));
        dp[0][0] = 0;
        for(int i=1;i<=m;i++) dp[i][0] = dp[i-1][0] + nums[i-1] * multipliers[i-1];
        for(int j=1;j<=m;j++) dp[0][j] = dp[0][j-1] + nums[n-j] * multipliers[j-1];
        for(int i =1;i<=m;i++){
            for(int j=1;i+j<=m;j++){
                dp[i][j] = max(dp[i][j-1] + nums[n-j] * multipliers[i+j-1], dp[i-1][j] + nums[i-1] * multipliers[i+j-1]);
            }
        }
        int ans = INT_MIN;
        for(int i=1;i<=m;i++){
            ans = max(ans, dp[i][m-i]);
        }
        return ans;
    }
};