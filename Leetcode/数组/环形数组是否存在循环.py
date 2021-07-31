class Solution:
    def circularArrayLoop(self, nums):
        n = len(nums)
        nxt = lambda x: (x + nums[x]) % n

        for i in range(n):
            if nums[i] == 0: continue
            slow = i
            fast = nxt(i)
            while nums[slow] * nums[fast] > 0 and nums[fast] * nums[nxt(fast)] > 0:
                if slow == fast:
                    if slow == nxt(slow):
                        break
                    else:
                        return True
                slow = nxt(slow)
                fast = nxt(nxt(fast))
            while nums[i] * nums[nxt(i)]> 0 :
                tmp = nxt(i)
                nums[i] = 0
                i = tmp
        return False