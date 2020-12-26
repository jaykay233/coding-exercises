class Solution {
public:
    typedef long long ll;
    vector<vector<ll>> cnt;
    vector<vector<ll>> dp;
    const int mod = 1e9+7;
    string target;
    int numWays(vector<string>& words, string target) {
        this->target=target;
        int n = words[0].size();
        int m = target.size();
        cnt = vector<vector<ll>>(n,vector<ll>(26));
        dp=vector<vector<ll>>(n,vector<ll>(m,-1));
        for(string word:words){
            for(int i =0;i<n;i++){
                cnt[i][word[i]-'a']++;
            }
        }
        return dfs(0,0,n,m) % mod;
    }

    int dfs(int i,int j,int n,int m){
        if(j==m) return 1;
        if(n-i<m-j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        long long val = dfs(i+1,j,n,m);
        val %= mod;
        val += dfs(i+1,j+1,n,m) * cnt[i][target[j]-'a'];
        val %= mod;
        return dp[i][j] = val;
    }
};