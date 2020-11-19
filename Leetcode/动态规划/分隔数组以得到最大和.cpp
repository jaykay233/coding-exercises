class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        const int n = arr.size();
        vector<int> dp(n+1);
        for(int i=1;i<=n;i++){
            int maxN = -1;
            for(int j=i-1;j>=max(i-k,0);j--){
                maxN = max(maxN,arr[j]);
                dp[i] = max(dp[i],dp[j] + maxN*(i-j));
            }
        }
        return dp[n];
    }
};