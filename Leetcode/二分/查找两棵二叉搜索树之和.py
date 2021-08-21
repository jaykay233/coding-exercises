# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def twoSumBSTs(self, root1: TreeNode, root2: TreeNode, target: int) -> bool:
        a, b = [], []
        self.dfs_LNR(root1, a)
        self.dfs_LNR(root2, b)
        an, bn = len(a), len(b)
        ######## 贪心，双指针，从两边向中间夹逼
        i = 0
        j = bn -1 
        while i < an and 0 <= j:
            if a[i] + b[j] == target:
                return True
            elif a[i] + b[j] < target:
                i += 1
            else:
                j -= 1  
        return False
    ############ 二叉树 中序遍历 ############
    def dfs_LNR(self, rt: TreeNode, res: List[int]) -> None:
        if rt == None:
            return
        self.dfs_LNR(rt.left, res)
        res.append(rt.val)
        self.dfs_LNR(rt.right, res)
