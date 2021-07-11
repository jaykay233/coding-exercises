#切成几块，记录左上角的位置来表示剩余pizza
#dp[r][c][cuts]表示submatrix[r,c,row-1,column-1]切割cuts刀的方法数
#https://leetcode-cn.com/problems/number-of-ways-of-cutting-a-pizza/solution/ji-yi-hua-di-gui-bu-xu-yao-guan-dpci-xu-rong-yi-xi/
#最终求的结果是dp[0][0][k-1]
import numpy as np
class Solution:
    def ways(self, pizza, k: int) -> int:
        module=int(1e9+7)
        rows,cols=len(pizza),len(pizza[0])
        G=np.array([np.array(['A'==ch for ch in s],dtype=bool) for s in pizza])
#        print(G)    #为了方便做子pizza切片，将pizza[]中的'A'True，'.'映射为False。用numpy库的array类非常方便
        # dfs: 以row行col列为左上角的矩形子pizza，切remain刀（按题目要求每一份都要有apple）的切法
        def dfs(row,col,remain):
            if remain<=0:   #已经不用切了
                return 1 if True in G[row:,col:] else 0#当前子pizza含有apple时算1种。否则不符合题目所需，算0种！
            cnt=0   #还要切remain刀。cnt记录最终切法数
            nr,nc=row,col
            while nr<rows and True not in G[nr,col:]: nr+=1   #跳过没有apple的行（切了不算数）
            while nr<rows-1:  #横着切
                nr+=1 #先+1，因为首次进入循环是pizza[nr][col:]恰好有apple，要切其下一行才对
                cnt=(cnt + dfs(nr,col,remain-1))%module     #分为 pizza[row:nr][col:]和pizza[nr:][col:] 两个子pizza
            while nc<cols and True not in G[row:,nc]:nc+=1   #跳过没有apple的列（切了不算数）
            while nc<cols-1:  #横着切
                nc+=1
                cnt=(cnt + dfs(row,nc,remain-1))%module
#            print(row,col,remain,cnt)
            return cnt
        return dfs(0,0,k-1)
