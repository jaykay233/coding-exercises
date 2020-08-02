class Solution(object):
    def stoneGameII(self, piles):
        """
        :type piles: List[int]
        :rtype: int
        """
        n = len(piles)
        d = {}
        sums = [0] * (n+1)
        for i in range(n-1,-1,-1):
            # print(piles[i])
            sums[i] = sums[i+1] + piles[i]
        
        # print(sums)
        
        def f(i,j):
            if i >= n:
                return 0
            if str(i)+"_"+str(j) in d:
                return d[str(i)+"_"+str(j)]
            max_value = 0
            
            for k in range(1,j*2+1):
                if k<=2*j and i+k<=n:
                    max_value = max(max_value, sums[i]-f(i+k,max(j,k)) )
            d[str(i)+"_"+str(j)] = max_value
            return d[str(i)+"_"+str(j)]
        return f(0,1)
        