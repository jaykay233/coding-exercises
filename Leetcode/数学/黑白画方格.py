class Solution:
    def paintingPlan(self,n,k):
        res=0
        def fact(n):
            if n ==0:
                return 1
            return n*fact(n-1)

        def combination(x,y):
            total = fact(y)//(fact(x)*fact(y-x))
            return int(total)

        for i in range(n):
            j = (k-i*n) //(n-i)
            if j == n:
                return 1
            if j*(n-i)==k-i*n and j>=0 and j<=n:
                res += (combination(i,n) * combination(j,n))

        return res 