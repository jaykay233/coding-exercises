class Solution(object):
    def splitIntoFibonacci(self, num):
        """
        :type num: str
        :rtype: List[int]
        """
        ans = []
        for i in range(len(num)):
            for j in range(i+1,len(num)):
                s1 = num[:i+1]
                s2 = num[i+1:j+1]
                if len(s1)>1 and s1[0] == '0':
                    continue
                if len(s2)>1 and s2[0] == '0':
                    continue
                s3 = str(int(s1) + int(s2))
                ans = [int(s1), int(s2), int(s3)]
                res = s1 + s2 + s3
                
                while len(res) < len(num):
                    # print(res)
                    if res != num[:len(res)]:
                        ans = []
                        break
                    s1 = s2
                    s2 = s3
                    s3 = str(int(s1) + int(s2))
                    if int(s1) > pow(2,31)-1 or int(s2) > pow(2,31) - 1 or int(s3) > pow(2,31) -1:
                        ans = []
                        break
                    res += s3
                    ans.append(int(s3))
                if res == num:
                    return ans
        return []
                    