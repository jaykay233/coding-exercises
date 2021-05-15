class Solution:
    def check(self, s, t): # 这里 t 可能为空
        if not t:
            return True
        if not s:
            return False
        
        return s.val == t.val and self.check(s.left, t.left) and self.check(s.right, t.right)

    def isSubStructure(self, A: TreeNode, B: TreeNode) -> bool:
        if not A or not B: return False
        return self.check(A, B) or self.isSubStructure(A.left, B) or self.isSubStructure(A.right, B)
