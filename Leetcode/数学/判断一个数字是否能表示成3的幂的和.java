class Solution {
    public static boolean checkPowersOfThree(int n) {
        int[] nums = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969};
        int idx = nums.length - 1;
        while (idx >= 0 && n > 0) {
            while (idx >= 0 && nums[idx] > n) {
                idx--;
            }

            if (nums[idx] == n) {
                return true;
            }

            n -= nums[idx];
            idx--;
        }
        return false;
    }
}