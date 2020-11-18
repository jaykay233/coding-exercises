class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int size = nums.size();
        int i =0;
        int ret =0;
        while(i<size){
            unordered_set<int> s = {0};
            int sum =0 ;
            while(i<size){
                sum += nums[i];
                if(s.find(sum-target)!=s.end()){
                    ret++;
                    break;
                }else{
                    s.insert(sum);
                    i++;
                }
            }
            i++;
        }
        return ret;
    }
};