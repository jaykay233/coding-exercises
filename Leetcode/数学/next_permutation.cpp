#include <vector>
#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

class Solution{
public:
    void nextPermutation(vector<int>& nums){
        if(nums.size()==0 || nums.size()==1) return;
        int len = nums.size();
        int first = -1;
        for(int i =len-1;i>=0;i--){
            if(nums[i-1] <nums[i]){
                first = i-1;
                break;
            }
        }
        if(first==-1) {
            sort(nums.begin(),nums.end());
            return;
        }
        int next_min = INT_MAX;
        int next_min_idx = -1;
        for(int j =first+1;j<len;j++){
            if(nums[j] < next_min){
                next_min = nums[j];
                next_min_idx = j;
            }
        }
        swap(nums[first],nums[next_min_idx]);
        sort(nums.begin()+first+1,nums.end());
        return;
    }
};