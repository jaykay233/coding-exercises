//https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/solution/shu-ju-jie-gou-he-suan-fa-san-chong-jie-4b9se/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two=0;
        for(int i=0;i<nums.size();i++){
            int n = nums[i];
            one = (one & (~two) & (~n)) | n & (~two) & (~one);
            two = (~n & two & ~one) | (n & ~two & ~one);
        }
        return one;
    }
};