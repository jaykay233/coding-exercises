class Solution(object):
    d = {}
    def getMoneyAmount(self, n):
        """
        :type n: int
        :rtype: int
        """
        return self.guessMoney(1,n)
        
    def guessMoney(self,low,high):
        if low>=high:
            return 0
        s = str(low)+"_" +str(high)
        if s in self.d:
            return self.d[s]
        
        min_value = 1e9
        for i in range(low,high+1):
            low_part = self.guessMoney(low,i-1)
            high_part = self.guessMoney(i+1,high)
            min_value = min(min_value, i + max(high_part,low_part))
        
        self.d[s] = min_value
        return self.d[s]
        