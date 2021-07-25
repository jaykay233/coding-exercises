//https://leetcode-cn.com/problems/sum-of-all-subset-xor-totals/solution/onsuan-fa-jian-ming-jiang-jie-by-yuyinsl-9sod/
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        int len = nums.size();
        for(int i =0;i<len;i++){
            ans |= nums[i];
        }
        return ans << (len-1);
    }
};