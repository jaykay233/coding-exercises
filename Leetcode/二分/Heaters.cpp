#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        // if(houses == heaters) return 0;
        int l = 0, r = 1e9;
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        cout<<houses.back()<<" "<<heaters.back()<<endl;
        return check(houses,heaters);
    }
    
    int check(vector<int>& houses,vector<int>& heaters){
        int idx =0 ;
        int dist = 0;
        int i;
        for(i = 0;i<houses.size();i++){
            // "i=6: 999"
            while(idx+1<heaters.size() && abs(houses[i]-heaters[idx]) >= abs(houses[i]-heaters[idx+1]) ) idx++;
            dist = max(dist, abs(houses[i] - heaters[idx]));
            while(i+1<houses.size() && houses[i]==houses[i+1]) i++;
        }
        return dist;
    }
};