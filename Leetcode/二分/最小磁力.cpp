#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(int x,vector<int>& position,int m){
        int pre = position[0], cnt = 1;
        for(int i=1;i<position.size();i++){
            if(position[i] - pre>=x){
                pre=position[i];
                cnt+=1;
            }
        }
        return cnt>=m;
    }

    int maxDistance(vector<int>& position, int m) {
        
    }
};