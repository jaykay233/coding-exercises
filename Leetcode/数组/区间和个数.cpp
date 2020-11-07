#include <bits/stdc++.h>
using namespace std;
class Solution{
public:  
    int countRangeSum(vector<int>& nums,int lower,int upper){
        long s = 0;
        vector<long> sums{0};
        for(auto& v:nums){
            s+=v;
            sums.push_back(s);
        }
        return countRangeSumInterval();
    }

    int countRangeSumInterval(vector<long>& sums,int left,int right,int lower,int upper){
        if(left==right) return 0;
        else{
            int mid = (left+right)/2;
            int n1 = countRangeSumInterval(sums,left,mid,lower,upper);
            int n2 = countRangeSumInterval(sums,mid+1,right,lower,upper);
            int ret = n1 + n2;
            int i = left;
            int l = mid + 1;
            int r  = mid + 1;
            while(i<=mid){
                while(l<=right && sums[l]-sums[i]<lower) l++;
                while(r<=right && sums[r] - sums[i]<=upper) r++;
                ret+=(r-l);
                i++;
            }
            vector<int> sorted(right-left+1);
            int p1=left,p2=mid+1;
            int p =0;
            while(p1<=mid || p2<=right){
                if(p1>mid)
                    sorted[p++] = sums[p2++];
                else if(p2>right)
                    sorted[p++] = sums[p1++];
                else{
                    if(sums[p1]<sums[p2])
                        sorted[p++] = sums[p1++];
                    else 
                        sorted[p++] = sums[p2++];
                }
            }
            for(int i=0;i<sorted.size();i++){
                sums[left+i] = sorted[i];
            }
            return ret;
        }
        return 0;
    }
};