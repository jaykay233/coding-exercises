class Solution {
public:
    vector<double> presum;
    Solution(vector<int>& w) {
        int tot = accumulate(w.begin(),w.end(),0);
        int cur_presum = 0;
        for(int x:w){
            cur_presum += x;
            presum.push_back((double)cur_presum/tot);
        }
    }
    
    int pickIndex() {
        return lower_bound(presum.begin(),presum.end(), (double)rand()/RAND_MAX) - presum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */