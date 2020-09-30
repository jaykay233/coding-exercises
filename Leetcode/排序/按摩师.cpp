#include <bits/stdc++.h>
using namespace std;
class Solution{
public:  
    int massage(vector<int>& nums){
        if(nums.empty()) return 0;
        int take = nums[0];
        int untake=0;
        int max_value = take;
        for(int i=1;i<nums.size();i++){
            max_value = max(nums[i]+untake,take);
            int tmp_untake = untake;
            untake = max(take,tmp_untake);
            take = nums[i] + tmp_untake;
        }
        return max_value;
    }
};