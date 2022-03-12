class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            vector<int> f;
            int length = 0;
            for (int j = i; j < n; j += k) {
                ++length;
                auto it = upper_bound(f.begin(), f.end(), arr[j]);
                if (it == f.end()) {
                    f.push_back(arr[j]);
                }
                else {
                    *it = arr[j];
                }
            }
            ans += length - f.size();
        }
        return ans;
    }
};

