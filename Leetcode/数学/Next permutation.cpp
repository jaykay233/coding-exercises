#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int j = -1;
        for(int i =len-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                j = i;
                break;
            }
        }
        if(j==-1) {
            reverse(nums.begin(),nums.end());
        }
        else{
            for(int i = len-1;i>j;i--){
                if(nums[i]>nums[j]){
                    swap(nums[i],nums[j]);
                    break;
                }
            }
            reverse(nums.begin()+j+1,nums.end());
        }
    }
};

int main(){
    return 0;
}