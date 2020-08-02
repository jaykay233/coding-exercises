#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size();
        vector<int> flip(n+1);
        int left= 0 ;
        int j = 0;
        int cnt = 0;
        for(int i =0;i<A.size();i++){
            while(j<n && flip[j] ^ A[j]){
                flip[j+1] ^= flip[j];
                j++;
            }
            if(j==n) break;
            cnt++;
            flip[j]^=1;
            if(j+K<=A.size()) flip[j+K]^=1;
            else return -1;
        }
        return cnt;
    }
};