class Solution {
public:
    const int mod = 1e9 + 7;
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        set<long long> st;
        long long all = 0, ans = 0;
        for (int i = 0; i < n; ++i) {
            st.insert(nums1[i]);
            all += abs(nums1[i] - nums2[i]);
        }
        long long maxn = 0;
        for (int i = 0; i < n; ++i) {
            auto it = st.lower_bound(nums2[i]);
            long long cur = abs(nums1[i] - nums2[i]);
            if (it != st.end()) {
                maxn = max(maxn, cur - abs(*it - nums2[i]));
            }
            if (it != st.begin()) {
                maxn = max(maxn, cur - abs(*(--it) - nums2[i]));
            }
        }
        return (all - maxn) % mod;
    }
};
