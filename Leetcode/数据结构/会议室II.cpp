#include <bits/stdc++.h>
using namespace std;
class Solution{
public:  
    int minMeetingRooms(vector<vector<int>>& intervals){
        if(intervals.size()==0) return false;

        sort(intervals.begin(),intervals.end());
        priority_queue<int,vector<int>,greater<int>> room;
        for(const auto& range:intervals){
            const int& start =range[0];
            const int& end = range[1];
            if(rooms.empty()){
                rooms.push(end);
                continue;
            }else if(room.top()<=start){
                room.pop();
                room.push(end);
            }else{
                room.push(end);
            }
        }
        return room.size();
    }
};