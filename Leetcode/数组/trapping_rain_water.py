class Solution(object):
    def trap(self,height):
        """
        :type height: list[int]
        :rtype int
        """
        ans = 0
        current =0 
        st = []
        while current <len(height):
            while len(st) and height[current] > height[st[-1]]:
                top = st[-1]
                st.pop()
                if not len(st):
                    break 
                distance = current - st[-1] - 1
                bounded_height = min(height[current],height[st[-1]]) - height[top]
                ans += distance * bounded_height
            st.append(current)
            current +=1 
        return ans 

class Solution2(object):
    def trap(self,height):
        """
        :type height: list[int]
        :rtype int
        """
        left = 0
        right = len(height)-1
        ans =0
        left_max =0 
        right_max =0 
        while left<right:
            if height[left]<height[right]:
                if height[left] >= left_max:
                    left_max = height[left]
                else:
                    ans += left_max - height[left]
                left += 1
            else:
                if height[right] > right_max:
                    right_max = height[right]
                else:
                    ans += right_max - height[right]
                right -=1 
        return ans