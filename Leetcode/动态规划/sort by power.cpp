#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
class Solution {
public:
    // memoization
    int dp[1000001];
    
    int getPower(int x) {
        if(dp[x] != -1) return dp[x];
        
        int power = 0;
        while(x != 1) {
            if(x % 2 == 0) {
                x = x / 2;
            } else {
                x = 3 * x + 1;
            }
            ++power;
        }

        return dp[x] = power;
    }
    
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> nums(hi - lo + 1);
        memset(dp, -1, sizeof dp);

        for(int i = 0, x = lo; x <= hi; ++i, ++x) {
            nums[i] = { getPower(x), x };
        }

        sort(nums.begin(), nums.end());
        return nums[k - 1].second;
    }

};