class Solution(object):
    def minSwapsCouples(self, row):
        """
        :type row: List[int]
        :rtype: int
        """
        N = len(row)/2
        fa = list(range(N))
        
        def find(i):
            if fa[i] == i:
                return i 
            fa[i] = find(fa[i])
            return fa[i]

        def merge(i,j):
            fi = find(i)
            fj = find(j)
            if fi!=fj:
                fa[fi] = fj 

        
        for i in range(0,len(row),2):
            merge(row[i]/2,row[i+1]/2)

        circle = 0
        for i in range(N):
            if fa[i]==i:
                circle +=1 

        return N - circle 
        