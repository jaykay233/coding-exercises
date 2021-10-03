#include <bist/stdc++.h>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        for(int i =0;i<len;i++){
            if(nums[i]!=i && nums[i]>=0 && nums[i]<len && nums[i]!=nums[nums[i]]){
                swap(nums[i],nums[nums[i]]);
                i--;
            }
        }
        
        
        for(int i = 0;i<len;i++){
            if(nums[i]!=i) return i;
        }
        return len;
    }
};