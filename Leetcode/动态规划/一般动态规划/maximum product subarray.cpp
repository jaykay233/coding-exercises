#include <vector>
#include <iostream>
#include <climits>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        // vector<int> gmin(n+1,1);
        // vector<int> gmax(n+1,1);
        int gmin = 1;
        int gmax = 1;
        int max_val = INT_MIN;
        for(int i =1;i<=n;i++){
            int valmin = gmin * nums[i-1];
            int valmax = gmax * nums[i-1];
            gmin = min(valmin,min(valmax,nums[i-1]));
            gmax = max(valmin,max(valmax,nums[i-1]));
            max_val = max(max_val,gmax);
            max_val = max(max_val,gmin);
            max_val = max(max_val,nums[i-1]);
        }
        return max_val;
    }
};