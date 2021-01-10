#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A,int K){
        double left = 0.0;
        double right = 1.0;
        int n =A.size();
        while(left<right){
            double mid = (right + left)/2.0;
            int cnt =0 ;
            vector<int> maxi = {0,1};
            int j = 0;
            for(int i =0;i<n;i++){
                while(j<n && A[i]>=mid * A[j]) j++;
                cnt += n-j;
                if(j<n && maxi[0]*A[j]<A[i]*maxi[1]) maxi={A[i],A[j]};
            }
            if(cnt==K) return maxi;
            if(cnt<K) left = mid;
            else right = mid;
        }
        return {};
    }
};