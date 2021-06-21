#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int left = 0;
        int right = citations.size();
        while(left<right){
            int mid = left + right >> 1;
            if(citations[mid] < citations.size() - mid){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return citations.size() - left;
    }
};