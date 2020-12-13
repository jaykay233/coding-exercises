class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        @functools.lru_cache(None)
        def dp(i,j,c):
            if i>=j:
                return 0
            if s[i]!=c:
                return dp(i+1,j,c)
            if s[j]!=c:
                return dp(i,j-1,c)
            return max(dp(i+1,j-1,chr(ord('a')+x)) for x in range(26) if chr(ord('a')+x)!=c)+2
        return max(dp(0,len(s)-1,chr(ord('a')+i)) for i in range(26))
