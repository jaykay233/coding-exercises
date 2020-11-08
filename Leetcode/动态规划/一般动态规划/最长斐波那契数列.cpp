class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int len = A.size();
        vector<vector<int>> dp(len,vector<int>(len));
        int maxlen = 0;
        unordered_map<int,int> m;
        for(int i =0;i<A.size();i++)
            m[A[i]]=i;
        for(int i =0;i<len;i++){
            for(int j =0;j<i;j++){
                if(A[i]-A[j]>=A[j] || !m.count(A[i]-A[j])) continue;
                int k = m[A[i]-A[j]];
                dp[j][i] = max(dp[j][i],dp[k][j]+1);
                maxlen = max(maxlen,dp[j][i]);
            }
        }
        return maxlen>0?maxlen + 2:0;
    }
};