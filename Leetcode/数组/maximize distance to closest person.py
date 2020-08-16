class Solution(object):
    def maxDistToClosest(self, seats):
        """
        :type seats: List[int]
        :rtype: int
        """
        seat_idx = []
        for i,val in enumerate(seats):
            if val == 1:
                seat_idx.append(i)
        min_dist = max(seat_idx[0]-0,len(seats)-1-seat_idx[-1]) 
        print(min_dist)
        for i in range(len(seat_idx)-1):
            min_dist = max(min_dist, (seat_idx[i+1] - seat_idx[i])/2)
            
        return min_dist
            