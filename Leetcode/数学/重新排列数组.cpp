class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int nn = n << 1;
        for(int src = 0; src < nn; src ++){
            int dst = src < n ? src * 2 : (src - n) * 2 + 1;
            nums[dst] |= (nums[src] & 0x3FF) << 10;
        }
        for(int src =0 ; src< nn ; src++){
            nums[src] >>= 10;
        }
        return nums;
    }
};