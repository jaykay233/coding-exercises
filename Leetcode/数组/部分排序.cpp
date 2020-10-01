#include <bits/stdc++.h>
using namespace std;

class Solution{
public:  
    vector<int> subSort(vector<int>& array){
        vector<int> res = {-1,-1};
        if(array.empty()) return res;
        int len = array.size();
        int max_value = INT_MIN;
        int min_value = INT_MAX;
        int first = -1;
        int last = -1;
        for(int i =0;i<array.size();i++){
            if(array[i]<max_value){
                last = i;
            }else{
                max_value = max(max_value,array[i]);
            }

            if(array[len-i-i]>min_value){
                first = i;
            }else{
                min_value = min(min_value,array[len-i-1]);
            }
        }
        return {first ,last};
    }
};