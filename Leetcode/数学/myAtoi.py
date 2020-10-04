class Solution(object):
    def myAtoi(self, s):
        """
        :type s: str
        :rtype: int
        """
        s = s.strip()
        i = 0 
        isfuhao = False
        while i < len(s):
            if not s[i].isdigit() and s[i]!='+' and s[i]!='-':
                break
            if s[i]=='+' or s[i] =='-':
                if isfuhao:
                    break
                isfuhao = True
                if i > 0:
                    break

            i += 1
        s = s[:i]
        print s 
        # print s 

        if isfuhao and len(s) == 1:
            return 0 
        print s 
        if len(s):
            s = int(s)
            if s < -2147483648:
                return -2147483648
            if s > 2147483647:
                return 2147483647
            return s 
        return 0
    