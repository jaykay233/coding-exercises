class Solution {
public:
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        vector<pair<int,int>> tmp;
        for(int i =0;i<height.size();i++){
            tmp.push_back(make_pair(height[i],weight[i]));
        }
        sort(tmp.begin(),tmp.end(),[](pair<int,int> a,pair<int,int> b){
            return a.first == b.first ? a.second >b.second : a.first < b.first;
        });
        vector<int> dp;
        for(const auto &[h,w]: tmp){
            auto p = lower_bound(dp.begin(),dp.end(),w);
            if(p == dp.end()) dp.push_back(w);
            else *p = w;
        }
        return dp.size();
    }
};