#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(int x,vector<int>& position,int m){
        int pre = position[0], cnt = 1;
        for(int i = 1;i<position.size();i++){
            if(position[i]>=pre + x){
                pre = position[i];
                cnt++;
            }
        }
        return cnt >= m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int l = 1, r = position.back() - position[0];
        int ans = -1;
        while(l<r){
            int mid = l + r + 1>> 1;
            if(check(mid, position,m)) {
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        return l;
    }
};