class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        int n = sweetness.size();
        vector<vector<int>> dp = vector<vector<int>>(n,vector<int>(k+1));
        dp[0][0] = sweetness[0];
        for(int i = 1;i<n;i++)
            dp[i][0] = dp[i-1][0] + sweetness[i];
        for(int j=1;j<=k;j++){
            for(int i =j;i<n;i++){
                int sum = 0;
                for(int m =i;m>=j;m--){
                    sum += sweetness[m];
                    dp[i][j] = max(dp[i][j], min(dp[m-1][j-1],sum));
                }
            }
        }
        return dp[n-1][k];
    }
};

class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        int sumSw=0;
        for(int i=0;i<sweetness.size();i++){
            sumSw+=sweetness[i];
        }
        int avg=sumSw/(k+1);
        int l=0,r=avg;
        while(l<=r){
            int mid=(r-l)/2+l;
            if(isFeasible(mid, k,sweetness))
            l=mid+1;
            else r=mid-1;
        }
        return r;
    }
    bool isFeasible(int minDiv,int k,vector<int> sweetness){
        int count=0,sum=0;
        for(int x:sweetness){
            sum+=x;
            if(sum>=minDiv){
                sum=0;
                count++;
            }
        }
        return count>=k+1;
    }
};
