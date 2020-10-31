class Solution(object):
    def isValidSerialization(self, preorder):
        """
        :type preorder: str
        :rtype: bool
        """
        preorder = preorder.split(',')
        cnt = 0
        for pre in preorder:
            if cnt>0:
                return False
            if pre.isdigit():
                cnt -= 1
            elif pre == '#':
                cnt += 1
            else:
                return False
            
        
        return cnt == 1