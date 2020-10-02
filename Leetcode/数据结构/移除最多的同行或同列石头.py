class Solution(object):
    def removeStones(self, stones):
        """
        :type stones: List[List[int]]
        :rtype: int
        """
        N = len(stones)
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

        for i in range(N):
            for j in range(i+1,N):
                if stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1]:
                    merge(i,j)
                
        cnt = 0
        for i in range(N):
            if fa[i] == i:
                cnt += 1

        return N - cnt