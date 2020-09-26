#include <bits/stdc++.h>
using namespace std;
class Solution{
public:  
    vector<int> bestLine(vector<vector<int>>& points){
        vector<int> a(2);
        int num;
        int maxn=0;
        int n = points.size();
        for(int i =0;i<n-1;i++){
            for(int j =i+1;j<n;j++){
                num = 2;
                long long x1 = points[j][0] - points[i][0];
                long long y1 = points[j][1] - points[i][1];
                if(n-1-j+1+1<=maxn) break;
                for(int k =j+1;k<n;k++){
                    long long x2 = points[k][0] - points[j][0];
                    long long y2 = points[k][1] - points[j][1];
                    if(x1*y2==x2*y1) num++;
                }
                if(num>maxn){
                    maxn = num;
                    a[0] = i;
                    a[1] = j;
                }
            }
        }
        return a;
    }
};