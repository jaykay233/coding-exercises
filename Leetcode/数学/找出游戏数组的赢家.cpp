#include <bits/stdc++.h>
using namespace std;

class Solution{
public: 
    int getWinner(vector<int>& arr,int k){
        int prev=max(arr[0],arr[1]);
        if(k==1) return prev;
        int maxnum = prev;
        int consecutive=1;
        for(int i=2;i<arr.size();i++){
            int cur = arr[i];
            if(prev>cur){
                consecutive++;
                if(consecutive>=k) return prev;
            }else{
                prev=cur;
                consecutive=1;
            }
            maxnum = max(maxnum,cur);
        }
        return maxnum;
    }
};