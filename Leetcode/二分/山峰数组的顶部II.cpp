class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int i =1 , j = n-2;
        int ans = 0;
        while(i<=j){
            int mid = i + j >> 1;
            if (arr[mid] > arr[mid + 1]) {
                ans = mid;
                j = mid - 1;
            }
            else {
                i = mid + 1;
            }
        }
        return ans;
    }
};