#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int K = req_skills.size();
        int S = 1<<K;
        unordered_map<string,int> m;
        for(auto& skill:req_skills) m[skill] = m.size();
        int N = people.size();
        vector<int> ps(N);
        for(int i=0;i<N;i++){
            for(auto& s:people[i])
                ps[i] |= (1<<m[s]);
        }
        const int INF = 1e9;
        vector<int> dp(S,INF);
        vector<vector<int>> path(S);
        dp[0] = 0;
        for(int i =0;i<people.size();i++){
            for(int j =S-1;j>=0;j--){
                if(j & ps[i]){
                    int k = j & (~ps[i]);
                    if(dp[k] + 1 < dp[j]){
                        dp[j] = dp[k] + 1;
                        path[j] = path[k];
                        path[j].push_back(i);
                    }
                }
            }
        }
        return path[S-1];
    }
};