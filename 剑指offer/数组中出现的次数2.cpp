#include <bits/stdc++.h>
using namespace std;
class Solution{
public:   
    int singleNumber(vector<int>& nums){
        int one = 0, two=0;
        for(int i=0;i<nums.size();i++){
            int n = nums[i];
            one = (one & (~two) & (~n)) | n & (~two) & (~one);
            two = (~n & two & ~one) | (n & ~two & ~one);
        }
        return one;
    }
};