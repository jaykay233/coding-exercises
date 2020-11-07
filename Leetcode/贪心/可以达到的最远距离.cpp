#include <bits/stdc++.h>
class Solution{
public:  
    int furthestBuilding(vector<int>& heights,int bricks,int ladders){
        int n = heights.size();
        priority_queue<int,vector<int>,greater<int>> q;
        int sumH = 0;
        for(int i=1;i<heights.size();i++){
            int deltaH = heights[i] - heights[i-1];
            if(deltaH>0){
                q.push(deltaH);
                if(q.size()>ladders){
                    sumH += q.top();
                    q.pop();
                }
                if(sumH>bricks)
                    return i - 1;
            }
        }
        return n-1;
    }
};