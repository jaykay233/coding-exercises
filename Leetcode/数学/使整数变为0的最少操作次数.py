class Solution(object):
    def minimumOneBitOperations(self,n):
        res=0
        while n>0:
            res ^= n 
            n >>= 1

        return res