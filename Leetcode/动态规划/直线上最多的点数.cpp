#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        vector<int> count;
        if(points.size()<2) return points.size();
        for(int i=0;i<points.size()-1;i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j=i+1;j<points.size();j++){
                if(points[i][0] == points[j][0] && points[i][1] == points[j][1])
                    continue;
                int x2 = points[j][0];
                int y2 = points[j][1];
                int numCount = 0;
                for(int i =0;i<points.size();i++){
                    if(isOnline(x1,y1,x2,y2,points[i][0],points[i][1])){
                        numCount++;
                    }
                }
                count.push_back(numCount);
            }
        }
        if(count.size()==0) return points.size();
        return *max_element(count.begin(),count.end());
    }


    bool isOnline(int x1,int y1,int x2,int y2,int x,int y){
        if(x1==x && y1==y) return true;
        else if(x2==x && y2==y) return true;
        else if((long long)(y2-y) * (x1-x) == (long long)(y1-y) * (x2-x))
            return true;
        return false;
    }
};