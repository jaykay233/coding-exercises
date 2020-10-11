#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string,bool> m;
    unordered_map<int,vector<string>> dp;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(string d:wordDict)
            m[d]=true;
        vector<string> res = dfs(s,0);
        return res;
    }

    vector<string> dfs(string& s,int i) {
        if(i==s.size()) return {""};
        if(dp.count(i)) return dp[i];
        vector<string> res;
        for(int j=i+1;j<=s.size();j++){
            string t = s.substr(i,j-i);
            if(!m.count(t)) continue;
            for(string a: dfs(s,j)) {
                if(!a.empty())
                    res.push_back(t+" "+a);
                else 
                    res.push_back(t);
            }
        }
        return dp[i] = res;
    }
};