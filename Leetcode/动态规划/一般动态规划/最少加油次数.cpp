#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int N = stations.size();
        vector<long> dp(N+1);
        dp[0] = startFuel;
        for(int i =0;i<N;i++){
            for(int t=i;t>=0;t--){
                if(dp[t]>=stations[i][0])
                    dp[t+1] = max(dp[t+1],dp[t] + (long)stations[i][1]);
            }
        }
        for(int i =0;i<=N;i++){
            if(dp[i]>=target) return i;
        }
        return -1;
    }
};

class Solution2 {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int ans =0,prev = 0;
        int tank = startFuel;
        for(auto& station:stations){
            int location = station[0];
            int capacity = station[1];
            tank -= location - prev;
            while(!pq.empty() && tank<0){
                tank+=pq.top();pq.pop();
                ans++;
            }
            if(tank<0) return -1;
            pq.push(capacity);
            prev=location;
        }

        {
            tank -= target-prev;
            while(!pq.empty() && tank<0){
                tank += pq.top();pq.pop();
                ans++;
            }
            if(tank<0) return -1;
        }
        return ans;
    }
};