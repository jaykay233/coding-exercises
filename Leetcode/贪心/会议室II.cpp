// https://leetcode-cn.com/problems/meeting-rooms-ii/solution/c-python3-fa-yi-chai-fen-fa-er-zui-xiao-d4wxw/
//贪心
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        pq.push(intervals[0][1]);
        for(int i = 1;i<intervals.size();i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            if(pq.top() <= start){
                pq.pop();
                pq.push(end);
            }else{
                pq.push(end);
            }
        }
        return pq.size();
    }
};

// 扫描线
class Solution(object):
    def minMeetingRooms(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        events = []
        for inter in intervals:
            events.append([inter[0],1])
            events.append([inter[1],-1])
        
        events.sort()
        meetings = 0
        rooms = 0
        for e in events:
            if e[1] > 0:
                meetings += 1
            else:
                meetings -= 1
            rooms = max(rooms,meetings)
        return rooms