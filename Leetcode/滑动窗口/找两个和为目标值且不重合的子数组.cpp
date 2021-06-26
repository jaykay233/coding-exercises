#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int size = arr.size(), left = 0, right, sum = 0, minSumOfLens = INT_MAX;
        vector<int> dp(size + 1, 0);
        dp[0] = size + 1;   
        for (right = 0; right < size; ++right) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left++];
            }
            if (sum == target) {
                int len = right - left + 1;   
                minSumOfLens = min(minSumOfLens, len + dp[left]);   
                dp[right + 1] = min(dp[right], len);   
            }
            else {
                dp[right + 1] = dp[right];   
            }
        }
        return minSumOfLens > size ? -1 : minSumOfLens;   
    }
};
