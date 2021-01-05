#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int ans =0 ;
        vector<bool> cut(A.size(),false);
        int len = A[0].size();
        for(int i =0;i<len;i++){
            bool sat = true;
            for(int j=1;j<A.size();j++){
                if(!cut[j-1] && A[j-1][i]>A[j][i]){
                    sat = false;
                    ans++;
                    break;
                }
            }

            if(!sat) continue;
            for(int j=1;j<A.size();j++){
                if(!cut[j-1] && A[j-1][i] < A[j][i])
                    cut[j-1] = true;
            }
        }
        return ans;
    }
};