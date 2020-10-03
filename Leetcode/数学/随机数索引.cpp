class Solution {
public:
    vector<int> nums;
    Solution(vector<int>& nums) {
        this->nums=nums;
    }
    
    int pick(int target) {
        int cnt =0;
        int res;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                if(!cnt++)
                    res = i;
                else{
                    int p = rand()%cnt;
                    if(p<1){
                        res = i;
                    }
                }
            }
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */