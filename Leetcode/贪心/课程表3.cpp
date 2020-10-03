#include <bits/stdc++.h>
using namespace std;

class Solution{
public:  
    int scheduleCourse(vector<vector<int>>& courses){
        priority_queue<int> pq;
        int time =0 ;
        sort(courses.begin(),courses.end(),[](auto a,auto b){
            return a[1]<b[1];
        });
        for(int i=0;i<courses.size();i++){
            vector<int> c = courses[i];
            if(time+c[0]<=c[1]){
                time += c[0];
                pq.push({c[0]});
            }else if(!pq.empty() && pq.top() > c[0]){
                auto p = pq.top();
                time += c[0] - p;
                pq.pop();
                pq.push(c[0]);
            }
        }
        return pq.size();
    }
};