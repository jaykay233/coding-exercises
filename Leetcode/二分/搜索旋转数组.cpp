#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& arr, int target) {
        int l = 0 , r = arr.size()-1;
        while(l<r){
            if(arr[l] < arr[r])
                break;
            int m = l + r >> 1;
            if(arr[m] <= arr[r])
                r = m;
            else 
                l = m + 1;
        }
        int one = binary_search(arr,0,l-1,target);
        int two = binary_search(arr,l,arr.size()-1,target);
        if(one!=-1){
            for(int i =0;i<=l-1;i++) {
                if(arr[i]==target) return i;
            }
        }
        if(two!=-1){
            for(int i =l;i<arr.size();i++){
                if(arr[i]==target) return i;
            }
        }
        return -1;
    }

    int binary_search(vector<int>& arr,int l,int r,int target){
        for(int i =l;i<=r;i++){
            if(arr[i]==target) return i;
        }
        return -1;
    }
};
