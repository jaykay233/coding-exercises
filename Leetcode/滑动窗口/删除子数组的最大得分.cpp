#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int len = nums.size();
        int l = 0;
        unordered_map<int,int> m;
        int sum = 0;
        int maxsum = 0;
        for(int i =0;i<len;i++){
            sum+=nums[i];
            m[nums[i]]++;
            while(m.size()<i-l+1){
                sum -= nums[l];
                m[nums[l]]--;
                if(m[nums[l]]==0) m.erase(nums[l]);
                l++;
            }
            maxsum = max(maxsum, sum);
        }
        return maxsum;
    }
};