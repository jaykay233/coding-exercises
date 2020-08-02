class Solution(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        def manacher(S):
            A = "#" + '#'.join(S) + '#'
            l = len(A)
            Z = [0] * l
            center = right = 0
            
            for i in range(l):
                if i<right:
                    Z[i] = min(Z[2*center-i],right-i)
                while i + Z[i]<l and i - Z[i]>=0 and A[i+Z[i]] == A[i-Z[i]]:
                    Z[i] += 1
                if i + Z[i] > right:
                    right = i + Z[i]
                    center = i
            
            return A, Z
        A, Z = manacher(s)
        # print(A)
        # print(Z)
        return sum(v/2 for v in Z)
        
        
    
        