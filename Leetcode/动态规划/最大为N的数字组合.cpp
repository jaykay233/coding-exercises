#include <bits/stdc++.h>
using namespace std;
int dp[10];
string s;
int n;
vector<string> DD;
class Solution {
public:

    int dfs(int cur, string ii,int lim, int zero){
        if(cur == s.size()) return 1;
        if(!lim && !zero && dp[cur]!=-1) return dp[cur];
        string v = DD[n-1];
        if(lim == 1) v = s.substr(cur, 1);
        int begin = 1;
        if(zero == 1) begin = 0;
        int ret = 0;
        for(int i=begin; i<n&&(DD[i]<=v); i++){
            if(i==0){
                ret += dfs(cur+1, DD[i], lim &(DD[i]==v), 1);
            }else{
                ret += dfs(cur+1, DD[i],lim&(DD[i]==v), 0);
            }
        } 
        if(!lim && !zero) dp[cur] = ret;
        return ret;
    }

    int atMostNGivenDigitSet(vector<string>& D, int N) {
        DD.clear();
        DD.push_back("0");
        for(auto item: D) DD.push_back(item);
        s = to_string(N);
        n = DD.size();
        memset(dp, -1, sizeof(dp));
        return dfs(0, "0",1, 1)-1;
    }
};
