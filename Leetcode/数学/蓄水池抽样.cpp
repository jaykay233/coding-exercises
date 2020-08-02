class Solution {
public:
    vector<int> v;
    Solution(vector<int>& nums) {
        v = nums;
    }
    
    int pick(int target) {
        int cnt =0, res = -1;
        for(int i =0;i<v.size();i+=1){
            if(v[i]!=target) continue;
            cnt+=1
            if(rand() % cnt ==0)  res = i;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */