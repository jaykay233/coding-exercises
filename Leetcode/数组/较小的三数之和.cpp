class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int total =0;
        for(int i =0;i<nums.size();i++){
            int l = i + 1;
            int r = nums.size()-1;
            int first = nums[i];
            while(l<r){
                if(nums[l] + nums[r]>=target-first){
                    r--;
                }else{
                    total += r - l ;
                    l++;
                }
            }
        }
        return total;
    }
};