import java.util.HashMap;
import java.util.Map;

public class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        int sum = 0;

        // key：区间 [0..i] 里所有元素的和 % k
        // value：下标 i
        Map<Integer, Integer> map = new HashMap<>();
        // 理解初始化的意义
        map.put(0, -1);
        int len = nums.length;
        for (int i = 0; i < len; i++) {
            sum += nums[i];
            if (k != 0) {
                sum = sum % k;
            }
            
            if (map.containsKey(sum)) {
                if (i - map.get(sum) > 1) {
                    return true;
                }
            } else {
                map.put(sum, i);
            }

        }
        return false;
    }
}
