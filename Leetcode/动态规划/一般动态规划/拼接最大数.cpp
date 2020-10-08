#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans;
        for(int n = max<int>(0,k-nums2.size()); n<=min<int>(k,nums1.size()); n++ ){
            int m = k - n;
            vector<int> maxm = selectMaxNumber(nums1,n);
            vector<int> maxn = selectMaxNumber(nums2,m);
            vector<int> tmp = mergeNumber(maxm,maxn);
            if(tmp>ans)
                ans = tmp;
        }
        return ans;
    }

private:
    vector<int> selectMaxNumber(vector<int>& nums,int m){
        int k = nums.size() - m;
        vector<int> st;
        auto it = nums.begin();
        while(it!=nums.end()){
            while(k>0 && !st.empty() && *it>st.back()) {st.pop_back();--k;}
            st.push_back(*it++);
        }
        while(k-->0) st.pop_back();
        return st;
    }

    vector<int> mergeNumber(const vector<int>& nums1, const vector<int>& nums2) {
        vector<int> ret;
        for (auto iter1 = nums1.begin(), iter2 = nums2.begin(); 
            iter1 != nums1.end() || iter2 != nums2.end(); ) {
                if (lexicographical_compare(iter1, nums1.end(), iter2, nums2.end()))
                    ret.push_back(*iter2++);
                else  ret.push_back(*iter1++);
            }
        return ret;
    }

};