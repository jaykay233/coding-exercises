class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        int n = nums.size();
        for (int right = 0; right < n; right++) {
            if (nums[right] != val) {
                nums[left] = nums[right];
                left++;
            }
        }
        return left;
    }
};