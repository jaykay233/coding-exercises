#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int calculate(const vector<int>& slices) {
        int n = slices.size();
        int choose = (n + 1) / 3;
        vector<vector<int>> dp(n + 1, vector<int>(choose + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= choose; ++j) {
                dp[i][j] = max(dp[i - 1][j], (i - 2 >= 0 ? dp[i - 2][j - 1] : 0) + slices[i - 1]);
            }
        }
        return dp[n][choose];
    }

    int maxSizeSlices(vector<int>& slices) {
        if(slices.empty()) return 0;
        vector<int> ans1 = vector<int>(slices.begin(),slices.end()-1);
        vector<int> ans2 = vector<int>(slices.begin()+1,slices.end());
        return max(calculate(ans1),calculate(ans2));
    }
};


class Solution2{
public:  
    int maxSizeSlices(vector<int>& slices){
        int n = slices.size();
        vector<int> linkL(n);
        vector<int> linkR(n);
        for(int i =0;i<n;i++){
            linkL[i] = (i==0?n-1:i-1);
            linkR[i] = (i==n-1?0:i+1);
        }

        vector<int> valid(n,1);
        priority_queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++){
            q.emplace(slices[i],i);
        }

        int ans =0 ;
        for(int i=0;i<n/3;i++){
            while(!valid[q.top().second]) q.pop();
            int pos = q.top().second;
            q.pop();
            ans+=slices[pos];
            slices[pos] = slices[linkL[pos]] + slices[linkR[pos]] - slices[pos];
            q.emplace(slices[pos],pos);
            valid[linkL[pos]] = valid[linkR[pos]] = 0;
            linkR[linkL[linkL[pos]]] = pos;
            linkL[linkR[linkR[pos]]] = pos;
            linkL[pos] = linkL[linkL[pos]];
            linkR[pos] = linkR[linkR[pos]];
        }
        return ans;
    }
};