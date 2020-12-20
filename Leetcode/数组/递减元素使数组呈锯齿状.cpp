class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        const int N = nums.size();
        int odd = 0, even = 0;
        int left = 0, right = 0;
        if(N < 2) return 0;
        for(int i = 0; i < N; i++){
            //找出左右两边元素
            if(i == 0){
                left = INT_MAX;
                right = nums[1];
            }
            else if(i == N - 1){
                left = nums[N - 2];
                right = INT_MAX;
            }
            else{
                left = nums[i - 1];
                right = nums[i + 1];
            }
            if(i % 2 != 0){
                //构造奇数波谷
                if(nums[i] >= left || nums[i] >= right){
                    odd += nums[i] - min(left, right) + 1;
                }
                else continue;
            }
            else{
                //构造偶数波谷
                if(nums[i] >= left || nums[i] >= right){
                    even += nums[i] - min(left, right) + 1;
                }
            }
        }
        return min(odd, even);
    }
};
