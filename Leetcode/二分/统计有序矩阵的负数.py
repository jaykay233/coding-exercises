class Solution:
    def countNegatives(self, grid):
        m,n=len(grid[0]),len(grid)
        res,ind = 0,m 
        for i in range(n):
            if ind ==0: break 
            if grid[i][ind-1]>=0:
                continue 
            cnt = 0
            while ind -1 >=0 and grid[i][ind-1]<0:
                ind -= 1
                cnt += 1
            res += cnt * (n-i)
        return res