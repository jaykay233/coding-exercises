class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int len = nums.size();
        int small = INT_MAX;
        int mid = INT_MAX;
        for(int i =0;i<nums.size();i++){
            int n = nums[i];
            if(n<=small)
                small = n; 
            else if(n<=mid){
                mid = n;
            }else if(n>mid) return true;
        }
        return false;
    }
};