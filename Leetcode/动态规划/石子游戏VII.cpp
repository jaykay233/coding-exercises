class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> sum(n,vector<int>(n,0));
        for(int i =0;i<n;i++){
            for(int j =i;j<n;j++){
                if(i==j) sum[i][j] = stones[i];
                else sum[i][j] = stones[j] + sum[i][j-1];
            }
        }

        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i =n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(i==j) dp[i][j]=max(stones[i],stones[j]);
                else dp[i][j] = max(sum[i+1][j] - dp[i+1][j],sum[i][j-1] - dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};