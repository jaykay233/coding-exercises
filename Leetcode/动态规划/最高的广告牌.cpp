class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        if(rods.size()<2){
            return 0;
        }
        int sum = accumulate(rods.begin(),rods.end(),0);
        vector<vector<int>> dp(rods.size(),vector<int>(sum+1,0));
        dp[0][rods[0]] = rods[0];
        int presum = rods[0];
        for(int i=1;i<rods.size();i++){
            for(int j =0 ;j<=presum;j++){
                if(dp[i-1][j] < j)
                    continue;
                dp[i][j] = max(dp[i][j],dp[i-1][j]);

                int k = j + rods[i];
                dp[i][k] = max(dp[i][k],dp[i-1][j] + rods[i]);

                k = abs(j-rods[i]);
                dp[i][k] = max(dp[i][k],dp[i-1][j] + rods[i]);
            }
            presum += rods[i];
        }

        return dp.back()[0]/2;
    }
};