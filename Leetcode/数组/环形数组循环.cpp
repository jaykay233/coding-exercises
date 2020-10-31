class Solution {
public:
    vector<int> nums;
    
    int getnext(int i){
        return (i+nums[i]+nums.size())%(nums.size());
    }

    bool circularArrayLoop(vector<int>& nums) {
        this->nums = nums;
        for(int i =0;i<nums.size();i++){
            if(nums[i]==0) continue;
            int slow = i;
            int fast = getnext(i);
            int val = nums[i];
            while(val * nums[fast]>0 && val * nums[getnext(fast)] >0){
                if(slow==fast){
                    if(slow==getnext(slow)) break;
                    return true;
                }
                slow = getnext(slow);
                fast = getnext(getnext(fast));
            }
            slow = i;
            while(val * nums[slow] > 0){
                int next = getnext(slow);
                nums[slow] = 0;
                slow = next;
            }
        }
        return false;
    }
};