class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n = books.size();
        vector<int> dp(n+1,INT_MAX/2);
        dp[0] = 0;
        for(int i =1;i<=n;i++){
            int h =0, w=0;
            for(int j=i-1;j>=0;j--){
                w+=books[j][0];
                h = max(h,books[j][1]);
                if(w>shelf_width)
                    break;
                dp[i]=min(dp[i],dp[j]+h);
            }
        }
        return dp[n];
    }
};