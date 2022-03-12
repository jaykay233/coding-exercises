class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxn = INT_MIN, right = -1;
        int minn = INT_MAX, left = -1;
        for(int i = 0;i<n;i++){
            if(maxn > nums[i]){
                right = i;
            }else{
                maxn = nums[i];
            }

            if(minn < nums[n-1-i]){
                left = n - 1 - i;
            }else{
                minn = nums[n-1-i];
            }
        }
        return right == -1 ? 0 : right - left + 1;
    }
};