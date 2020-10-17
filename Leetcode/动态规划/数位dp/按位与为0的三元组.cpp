#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countTriplets(vector<int>& A) {
        vector<int> m(65537);
        int mask = (1 << 16) - 1;
        for(int a:A){
            int k = mask ^ a;
            int i = k;
            while(i){
                m[i]++;
                i = (i-1) & k;
            }
            m[0]++;
        }
        int res =0 ;
        for(int a:A){
            for(int b:A)
                res += m[a&b];
        }
        return res;
    }
};