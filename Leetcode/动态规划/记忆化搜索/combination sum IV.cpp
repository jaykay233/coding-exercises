#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
class Solution{
public: 
    int combinationSum4(vector<int>& nums,int target){
        unordered_map<int,int> memo;
        return helper(nums,target,memo);
    }

    int helper(vector<int>& nums,int target,unordered_map<int,int>& memo){
        if(target<0) return 0;
        if(target==1) return 1;
        if(memo.count(target)) return memo[target];
        int res = 0;
        for(int i =0;i<nums.size();i++){
            res += helper(nums,target-nums[i],memo);
        }
        return memo[target] = res;
    }
};

class Solution2{
public: 
    int combinationSum4(vector<int>& nums,int target){
        vector<int> dp(target+1);
        for(int i =1;i<=target;i++){
            for(int a:nums){
                if(i>=a)
                    dp[i] += dp[i-a];
            }
        }
        return dp.back();
    }
}