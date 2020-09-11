#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        return getanswer(nums,left,right);
    }

    int getanswer(vector<int>& nums,int left,int right){
        if(left>right){
            return -1;
        }
        int mid = left + right >> 1;
        int left_answer = getanswer(nums,left,mid-1);
        if(left_answer!=-1)
            return left_answer;
        else if(nums[mid] == mid)
            return mid;
        return getanswer(nums,mid+1,right);
    }
};