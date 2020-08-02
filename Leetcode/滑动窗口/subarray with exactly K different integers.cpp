//恰好k次等于最多k次减去最多k-1次。
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
       auto subarrays = [&A](int k){
           vector<int> count(A.size()+1);
           int ans =0 ;
           int i =0;
           for(int j =0;j<A.size();j++){
               if(count[A[j]]++ == 0) 
                 k--;
               while(k<0){
                   if(--count[A[i++]]==0) k++;
               }
               ans+=j-i+1;
           }
           return ans;
       };     
        return subarrays(K) - subarrays(K-1);
    }
};