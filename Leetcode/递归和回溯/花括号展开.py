class Solution(object):
    def expand(self, s):
        if '{' not in s and '}' not in s and ',' not in s:
            return [s]
        """
        :type s: str
        :rtype: List[str]
        """
        nums = []
        temp = []
        i = 0
        while i < len(s):
            if s[i].isalpha():
                while i < len(s) and s[i].isalpha():    
                    temp.append(s[i])
                    i += 1
                nums.append(temp)
                temp = []
            elif s[i] == '{':
                j = i
                cnt = 0
                while j < len(s):
                    if s[j] == '{':
                        cnt += 1
                    if s[j] == '}':
                        cnt -= 1
                    if cnt == 0:
                        break
                    j += 1
                t = s[i+1:j]
                i = j + 1
                temp.extend(t.split(','))
                nums.append(temp)
                temp = []
        else:
            if len(temp):
                nums.append(temp)
                temp = []
        
        res = []
        comb = []
        def recur(nums, i):
            if i == len(nums):
                res.append(''.join(comb))
                return
            
            for c in nums[i]:
                comb.append(c)
                recur(nums, i + 1)
                del comb[len(comb)-1]
        
        recur(nums, 0)
        res = sorted(res)
        return res
