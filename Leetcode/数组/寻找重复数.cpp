class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),0);
        for(int i =1;i<=n;i++){
            if(i!=nums[i] && nums[i]>=1 && nums[i]<=n && nums[i]!=nums[nums[i]]){
                swap(nums[i],nums[nums[i]]);
                i--;
            }
        }
        for(int i =1;i<=n;i++){
            if(nums[i]!=i) return nums[i];
        }
        return -1;
    }
};