class Solution:
    def isNumber(self, s: str) -> bool:
        s=s.strip()
        state = 0
        s = list(s)
        for i in s:
            if state == 0:
                if i == '.':state = 8
                elif '0'<=i<='9':state = 1
                elif i == '+' or i == '-':state = 7
                else: return False
            elif state == 1:
                if '0'<=i<='9':state = 1
                elif i == 'e' or i == 'E':state = 4
                elif i == '.':state = 2
                else:return False
            elif state == 2:
                if '0'<=i<='9':state = 3
                elif i == 'e' or i == 'E':state = 4
                else: return False
            elif state == 3:
                if '0'<=i<='9':state = 3
                elif i == 'e' or i == 'E': state = 4
                else:return False
            elif state == 4:
                if '0'<=i<='9':state = 6
                elif i == '+' or i == '-':state = 5
                else:return False
            elif state == 5:
                if '0'<=i<='9':state = 6
                else: return False
            elif state == 6:
                if '0'<=i<='9':state = 6
                else: return False
            elif state == 7:
                if '0'<=i<='9':state = 1
                elif i == '.':state=8
                else:return False
            elif state == 8:
                if '0'<=i<='9':state = 3
                else: return False
        return state in [1,2,3,6]