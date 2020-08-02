#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res =0 ;
        unordered_map<int,int> tr_left, tr_right;
        for(auto& x:nums){
            int left = tr_right[x-1];
            int right = tr_left[x+1];
            tr_left[x-left] = max(tr_left[x-left],left + 1 + right);
            tr_right[x+right] = max(tr_right[x+right],left + 1+ right);
            res = max(res,left+1+right);
        }
        return res;
    }
};

int main(){

    return 0;
}
