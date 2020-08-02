class Solution(object):
    def sortArray(self,nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        def heapify(nums,i,n):
            l = i * 2 + 1
            r = i * 2 + 2
            largest = i
            if i < n and nums[largest] < nums[l]:
                largest = l 
            if r < n and nums[largest] < nums[r]:
                largest = r 
            if largest != i:
                nums[largest], nums[i] = nums[i], nums[largest]
                heapify(nums,largest,n)

        n = len(nums)
        for i in range(int(n//2),-1,-1):
            heapify(nums,i,n)

        for j in range(n-1,-1,-1):
            nums[j], nums[0] = nums[0], nums[j]
            heapify(nums,0,j)

        return nums 