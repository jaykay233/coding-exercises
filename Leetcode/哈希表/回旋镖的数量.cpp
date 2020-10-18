#include<unordered_map>
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;
        for(int i = 0; i < points.size(); i ++){
            unordered_map<int,int> mp;
            for(int j = 0; j < points.size(); j ++){
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                mp[ dx * dx + dy * dy ]  ++;
            }
            for(auto x:mp){
                ans += x.second * (x.second - 1);
            }
        }
        return ans;
    }
};
