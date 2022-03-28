INT_MAX = 2 ** 31 - 1
INT_MIN = -2**31

class Automation:
    def __init__(self) -> None:
        self.start = 'start'
        self.sign = 1
        self.ans = 0
        self.table = {
            'start':['start','signed','in_number','end'],
            'signed':['end','end','in_number','end'],
            'in_number':['end','end','in_number','end'],
            'end':['end','end','end','end']
        }

    def get_col(self, c):
        if c.isspace():
            return 0
        if c == '+' or c =='-':
            return 1
        if c.isdigit():
            return 2
        return 3 

    def get(self,c):
        self.start = self.table[self.start][self.get_col(c)]
        if self.start == 'in_number':
            self.ans = self.ans * 10 + int(c)
            self.ans = min(self.ans, INT_MAX) if self.sign ==1 else min(self.ans, -INT_MIN)
        elif self.start == 'signed':
            self.sign = 1 if c == '+' else -1 
    
class Solution:
    def myAtoi(self, s):
        automation = Automation()
        for c in s:
            automation.get(c)
        return automation.sign * automation.ans