#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        int p1 = 0,p2 =0 ,p3 =0 ;
        vector<int> res;
        while(p1<arr1.size() && p2<arr2.size() && p3<arr3.size()){
            if(arr1[p1] == arr2[p2] && arr2[p2] == arr3[p3]) res.push_back(arr1[p1]);
            int m =  min(arr1[p1],min(arr2[p2],arr3[p3]));
            if(m==arr1[p1]) p1++;
            if(m==arr2[p2]) p2++;
            if(m==arr3[p3]) p3++;
        }
        return res;
    }
};