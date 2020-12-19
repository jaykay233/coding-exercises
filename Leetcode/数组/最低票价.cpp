class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int last = days[days.size()-1];

        vector<int> dp(last+1, 0);
        int idx = 0;

        for (int i = 1; i <= last; i++) {
            if (i == days[idx]) {
                int cost = INT_MAX;
                int oneDayAgo = i-1;
                int sevenDaysAgo = i-7>0?i-7:0;
                int thirtyDaysAgo = i-30>0?i-30:0;

                cost = min(dp[oneDayAgo] + costs[0], cost);
                cost = min(dp[sevenDaysAgo] + costs[1], cost);
                cost = min(dp[thirtyDaysAgo] + costs[2], cost);

                dp[i] = cost;

                idx++;
            } else {
                dp[i] = dp[i-1];
            }
        }

        return dp[last];
    }
};
