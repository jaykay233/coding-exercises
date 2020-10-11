#include <bits/stdc++.h>
using namespace std;
class Solution{
public:  
    int closestToTarget(vector<int>& arr,int target){
        int ans = abs(arr[0]-target);
        vector<int> valid  = {arr[0]};
        for(int i=1;i<arr.size();i++){
            vector<int> valid_new = {arr[i]};
            for(int pre:valid){
                valid_new.push_back(pre & arr[i]);
                ans = min(ans,abs((pre & arr[i]) - target ));
            }
            valid_new.erase(unique(valid_new.begin(),valid_new.end()),valid_new.end());
            valid = valid_new;
        }
        return ans;
    }
};