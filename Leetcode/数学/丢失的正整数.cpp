#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),0);
        for(int i =1;i<=n;i++){
            while(nums[i]>=1 && nums[i]<=n && nums[nums[i]]!=nums[i]){
                swap(nums[nums[i]],nums[i]);
                i--;
            }
        }
        for(int i =1;i<nums.size();i++){
            if(nums[i]!=i) return i;
        }
        return nums.size();
    }
};
