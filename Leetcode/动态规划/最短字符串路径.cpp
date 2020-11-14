class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        int n = A.size();
        vector<vector<int>> dis(n,vector<int>(n));
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(i==j) continue;
                dis[i][j] = 0;
                for(int len=min(A[i].size(),A[j].size());len>0;len-- ){
                    if(A[i].substr(A[i].size()-len,len)==A[j].substr(0,len)){
                        dis[i][j] = len;
                        break;                        
                    }
                }
            }
        }

        int sz = 1<<n;
        vector<vector<int>>dp(sz,vector<int>(n,INT_MAX));
        vector<vector<int>> pre(sz,vector<int>(n));
        for(int i=1;i<sz;i++){
            for(int j =0;j<n;j++){
                if((i&(1<<j))==0 ) continue;
                int num =0;
                for(int k =0;k<n;k++){
                    if(k==j || (i&(1<<k)) ==0) continue;
                    num++;
                    int tmp = dp[i^(1<<j)][k] + A[j].size() - dis[k][j];
                    if(tmp<dp[i][j]){
                        dp[i][j] = tmp;
                        pre[i][j] = k;
                    }
                }
                if(num==0){
                    pre[i][j] = j;
                    dp[i][j] = A[j].size();
                }
            }
        }
        int ans = INT_MAX;int id=0;
        for(int j =0;j<n;j++){
            if(dp[sz-1][j]<ans){
                ans = dp[sz-1][j];
                id = j;
            }
        }
        vector<int> ve(n);
        ve[n-1] = id;
        int state = sz-1;
        for(int i=n-2;i>=0;i--){
            ve[i] = pre[state][id];
            state = state ^ (1<<id);
            id = ve[i];
        }

        string s = A[ve[0]];
        for(int i=1;i<n;i++){
            s+=A[ve[i]].substr(dis[ve[i-1]][ve[i]]);
        }
        return s;
    }
};