## 记忆话搜索会超时
from functools import lru_cache
class Solution:
    def makeArrayIncreasing(self, arr1: List[int], arr2: List[int]) -> int:
        l1, l2 = len(arr1), len(arr2)
        arr2.sort()
        
        @lru_cache(None)
        def dfs(i1, i2, pre):
            if i1 >= l1:
                return 0
            i2 = bisect.bisect(arr2, pre)
            return min(1 + dfs(i1 + 1, i2, arr2[i2]) if i2 < l2 else l2+1,\
                       dfs(i1 + 1, i2, arr1[i1]) if pre < arr1[i1] else l2+1)
        
        res = dfs(0, 0, float("-inf"))
        return -1 if res > l2 else res


## ac版本
class Solution:
    def makeArrayIncreasing(self, arr1: List[int], arr2: List[int]) -> int:
        l1, l2 = len(arr1), len(arr2)
        arr2.sort()
        
        dp = {0: arr1[0], 1: arr2[0]}
        for i in range(1, l1):
            new_dp = {}
            for k, v in dp.items():
                if arr1[i] > v and (k not in new_dp or new_dp[k] > arr1[i]):
                    new_dp[k] = arr1[i]
                j = bisect.bisect(arr2, v)
                if j < l2 and (k + 1 not in new_dp or new_dp[k + 1] > arr2[j]):
                    new_dp[k+1] = arr2[j]
            dp = new_dp
        if len(dp) == 0:
            return -1
        return min(dp.keys())
