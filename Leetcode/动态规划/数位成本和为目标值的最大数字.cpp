#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
   int cost[9 + 5];
   string dp[9 + 5][5000 + 5];
   string string_max(const string &lhs, const string &rhs) {
       if (lhs.size() > rhs.size()) return lhs;
       if (rhs.size() > lhs.size()) return rhs;
       if (lhs > rhs) return lhs;
       else return rhs;
   }
   string largestNumber(vector<int>& c, int target) {
       int len = c.size();
       for (int i = 0; i < len; ++i) {
           cost[i + 1] = c[i];
       }
       for (int j = 0; j <= target; ++j) {
           dp[0][j] = '#';
       }
       dp[0][0] = "";
       for (int i = 1; i <= 9; ++i) {
           for (int j = 0; j <= target; ++j) {
               string a, b;
               a = dp[i - 1][j];
               if (j - cost[i] >= 0 && dp[i][j - cost[i]] != "#")
                   b = std::to_string(i) + dp[i][j - cost[i]];
               dp[i][j] = string_max(a, b);
           }
       }
       if (dp[9][target] == "#") return "0";
       else return dp[9][target];
   }
};
