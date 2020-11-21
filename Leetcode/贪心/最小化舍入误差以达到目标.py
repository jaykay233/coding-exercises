#https://leetcode-cn.com/problems/minimize-rounding-error-to-meet-target/solution/zhuan-hua-wei-topkwen-ti-by-user2198v/
from math import floor,ceil
class Solution:
    def minimizeError(self, prices: List[str], target: int) -> str:
        
        prices = [float(i) for i in prices]
        floor_prices = [floor(i) for i in prices]
        ceil_prices = [ceil(i) for i in prices]
        Min,Max = sum(floor_prices),sum(ceil_prices)
        #print(Min,Max)
        if target < Min or target > Max:
            return '-1'
        
        k = target-Min
        err = sum(prices)-Min
        errors = [abs(floor_prices[i]-prices[i])-abs(ceil_prices[i]-prices[i]) for i in range(len(prices))]
        errors = sorted(errors)[::-1]
        return '%.3f' % (err-sum(errors[:k]))
