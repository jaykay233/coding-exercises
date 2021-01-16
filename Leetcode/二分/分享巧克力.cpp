#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(vector<int>& sweetness,int val,int K){
        int sum = 0;
        int cnt = 0;
        for(int v:sweetness){
            sum+=v;
            if(sum>=val){
                cnt++;
                sum = 0;
            }
        }   
        if(sum>=val) cnt++;
        return cnt>=K+1;
    }

    int maximizeSweetness(vector<int>& sweetness, int K) {
        int l = *min_element(sweetness.begin(),sweetness.end());
        int r = accumulate(sweetness.begin(),sweetness.end(),0);
        while(l<r){
            int mid = (l + r + 1)>>1;
            if(check(sweetness,mid,K)) l = mid;
            else r = mid-1;    
        }
        return l;
    }
};