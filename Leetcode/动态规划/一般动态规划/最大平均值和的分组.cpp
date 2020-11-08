#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        vector<double> sums(A.size()+1);
        for(int i =0;i<A.size();i++) sums[i+1] = sums[i] + A[i];
        vector<vector<double>> dp(A.size(),vector<double>(K+1));
        dp[0][1] = A[0];
        for (int i = 1; i < A.size(); ++i) {
            dp[i][1] = sums[i + 1] / (i + 1);
            for (int j = 2; j <= i + 1 && j <= K; ++j) {
                for (int u = i; u >= j - 1; --u) {
                    dp[i][j] = max(dp[i][j], dp[u - 1][j - 1] + (sums[i + 1] - sums[u]) / (i + 1 - u));
                }
            }
        }
        return dp[A.size()-1][K];
    }
};