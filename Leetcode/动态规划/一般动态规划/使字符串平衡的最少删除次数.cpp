class Solution {
public:
    bool isa(char c){
        return c == 'a';
    }

    bool isb(char c){
        return c == 'b';
    }

    int minimumDeletions(string s) {
        int len = s.size();
        vector<vector<int>> dp(len+1,vector<int>(2));

        for(int i=1;i<=len;i++){
            dp[i][0] = dp[i-1][0] + isb(s[i-1]);
            dp[i][1] = min(dp[i-1][0],dp[i-1][1]) + isa(s[i-1]);
        }
        return min(dp[len][0],dp[len][1]);
    }
};