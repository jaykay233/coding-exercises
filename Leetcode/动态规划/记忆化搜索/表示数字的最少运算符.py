class Solution:
    def leastOpsExpressTarget(self, x: int, target: int) -> int:
        from functools import lru_cache
        d = {}

        @lru_cache(None)
        def dfs(cur):
            if cur in d:
                return d[cur]
            if cur < x:
                return min(2 * cur - 1, (x - cur) * 2)
            if cur == 0:
                return 0
            p = int(math.log(cur, x))
            sums = x ** p
            ans = dfs(cur - sums) + p
            if sums * x - cur < cur:
                ans = min(ans, p + 1 + dfs(sums * x - cur))
            d[cur] = ans
            return ans 

        return dfs(target)