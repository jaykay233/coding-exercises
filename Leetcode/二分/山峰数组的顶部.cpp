class Solution 
{
public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {
        int n = arr.size();
        int l = 1;
        int r = n - 2;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (arr[mid] < arr[mid + 1])
                l = mid + 1;
            else
                r = mid;
        }

        return l;
    }
};