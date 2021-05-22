#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        if(n<=0) return 0;
        int d[100005][2];
        memset(d,0,sizeof d);
        d[0][0] = arr[0];
        d[0][1] = INT_MIN;
        int res = max(d[0][0],d[0][1]);
        for(int i =1;i<n;i++){
            d[i][0] = max(d[i-1][0] + arr[i],arr[i]);
            d[i][1] = max(d[i-1][0], (d[i-1][1] == INT_MIN?0:d[i-1][1]) + arr[i]);
            res = max(res,max(d[i][0],d[i][1]));
        }

        return res;
    }
};