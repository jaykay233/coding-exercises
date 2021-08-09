#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0;
        int i = 0;
        while(i<nums.size()){
            int value = nums[i];
            nums[idx++] = value;
            while(i<nums.size() && nums[i] == value) i++;
        }
        return idx;
    }
};