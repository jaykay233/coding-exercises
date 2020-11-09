class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        if len(arr)<2:
            return 0
        ans=0
        for i in range(len(arr)):
            temp=arr[i]
            for j in range(i+1,len(arr)):
                temp=temp^arr[j]
                if temp==0:
                    ans+=j-i
        return ans