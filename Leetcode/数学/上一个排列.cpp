#include <iostream>
#include <vector>
using namespace std;


// \     /
//  \   /
//   \ /

void previousPermutation(vector<int>& nums){
    int n = nums.size();
    int j = n - 2;
    while(j>=0 && nums[j] <= nums[j+1]) j --;
    if(j<0) {
        sort(nums.begin(),nums.end());
        reverse(nums.begin(), nums.end());
        return;
    }
    int k = j + 1;
    while(k<n && nums[k] < nums[j]) k++;
    swap(nums[j] , nums[k-1]);
    sort(nums.begin() + j + 1, nums.end());
    reverse(nums.begin() + j + 1, nums.end());
    return;
}


int main()
{
    vector<int> res = {1,3,2,3};
    previousPermutation(res);
    for(int i = 0;i<res.size();i++){
        cout << res[i] << " ";
    }
    return 0;
}