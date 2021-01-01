#include <bits/stdc++.h>
using namespace std;

class Solution{
public:  
    typedef long long ll;
    static const int mod = 1e9+7;
    int maxSum(vector<int>& nums1,vector<int>& nums2){
        int i =0,j=0;
        int m = nums1.size();
        int n = nums2.size();
        ll best1=0;
        ll best2=0;
        while(i<m || j<n){
            if(i<m && j<n){
                if(nums1[i]<nums2[j]){
                    best1 += nums1[i];
                    i++;
                }else if(nums2[j]<nums1[i]){
                    best2+=nums2[j];
                    j++;
                }else{
                    ll best = max(best1,best2) + nums1[i];
                    best1 = best2 = best;
                    i++;
                    j++;
                }
            }else if(i<m){
                best1 += nums1[i];
                i++;
            }else if(j<n){
                best2 += nums2[j];
                j++;
            }
        }
        return (max(best1,best2)+mod)%mod;
    }
};