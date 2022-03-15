class Solution:
    def maxInvestment(self, product: List[int], limit: int) -> int:
        product.sort()
        lo,hi = 0,product[-1]
        while lo < hi:
            mid = (lo + hi + 1) >> 1
            cnt = 0
            for i in range(bisect_left(product,mid),len(product)):
                cnt += product[i] - mid + 1
            if cnt < limit:
                hi = mid - 1
            else:
                lo = mid 
        
        ans = 0
        for i in range(bisect_right(product,lo), len(product)):
            limit -= product[i] - lo
            ans += (product[i] - lo) * (lo + 1 + product[i]) //2 % 1_000_000_007
        ans += limit * lo;
        return ans % 1_000_000_007