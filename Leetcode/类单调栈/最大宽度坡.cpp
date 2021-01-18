#include <bits/stdc++.h>
using namespace std;
class Solution{
public:  
    int maxWidthRamp(vector<int>& A){
        stack<int> s;
        for(int i =0;i<A.size();i++){
            if(s.empty() || A[i]<A[s.top()]){
                s.push(i);
            }
        }
        int ans =0 ;
        for(int j=A.size()-1;j>=ans;j--){
            while(!s.empty() && A[j]>=A[s.top()]){
                ans = max(ans,j-s.top());
                s.pop();
            }
        }
        return ans;
    }
};