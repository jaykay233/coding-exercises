#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int jobScheduling(vector<int>& startTime,vector<int>& endTime,vector<int>& profit){
        int n = startTime.size();
        vector<vector<int>> jobs(n);
        for(int i=0;i<n:i++){
            jobs[i].push_back(startTime[i]);
            jobs[i].push_back(endTime[i]);
            jobs[i].push_back(profit[i]);
        }

        auto cmp=[&](const vector<int> &x, const vector<int>& y){
            return x[1] < y[1];
        };

        sort(jobs.begin(),jobs.end());
        vector<int> f(n);
        f[0]=jobs[0][2];
        for(int i=1;i<n;i++){
            int l =0,r = i-1;
            while(l<r){
                int mid = (l + r + 1)>>1;
                if(jobs[mid][1] <= jobs[i][0])
                    l = mid;
                else
                    r = mid-1;
            }
            if(jobs[l][1]<=jobs[i][0])
                f[i] = max(f[i-1],f[l] + jobs[i][2]);
            else
                f[i] = max(f[i-1],jobs[i][2]);
        }
        return f[n-1];
    }
};