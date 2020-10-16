class Solution {
public:
    vector<vector<int>> res;
    vector<int> ans;
    int n;
    int m;
    int k;

    int dp[55][110][55];
    
    const int mod = 1e9+7;

    int numOfArrays(int n, int m, int k) {
        this->n = n;
        this->m = m;
        this->k = k;
        memset(dp,-1,sizeof dp);
        int value = search(0, 0, 0);
        return value;
    }

    int search(int idx, int max_value,int cost){
        if(idx==n){
            if(cost==k) return 1;
            return 0;
        }
        if(dp[idx][max_value][cost]!=-1) return dp[idx][max_value][cost];
        int ans =0 ;
        for(int i =1;i<=m;i++){
            if(i>max_value)
                ans+=search(idx+1,i,cost+1);
            else
                ans+=search(idx+1,max_value,cost);
            ans%=mod;
        }
        return dp[idx][max_value][cost] = ans%mod;
    }
};