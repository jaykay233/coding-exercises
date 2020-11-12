#include <bits/stdc++.h>
using namespace std;
class Solution{
public:  
    int lastStoneWeightII(vector<int>& stones){
        int sum = accumulate(stones.begin(),stones.end(),0);
        vector<bool> dp(sum/2+1,false);
        dp[0] = true;
        for(int i =0;i<stones.size();i++){
            for(int w=dp.size()-1;w>=stones[i];w--){
                dp[w] = dp[w] | dp[w-stones[i]];
            }
        }
        for(int i=dp.size()-1;i>=0;i--){
            if(dp[i]==true)
                return sum - 2 * i;
        }
        return sum;
    }
};