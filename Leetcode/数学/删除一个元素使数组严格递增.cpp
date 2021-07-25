class Solution {
  public boolean canBeIncreasing(int[] nums) {
    int cnt = 0;
    for (int i = 1; i < nums.length && cnt <= 1; i++) {
      if (nums[i] > nums[i - 1]) continue;
      cnt++;
      if (i - 1 > 0 && nums[i] <= nums[i - 2]) {
        nums[i] = nums[i - 1];
      } //else {
        //nums[i - 1] = nums[i];
      //}
    }
    return cnt <= 1;
  }
}
