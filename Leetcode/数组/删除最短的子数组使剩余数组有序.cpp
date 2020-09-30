#include <bits/stdc++.h>
using namespace std;
const int maxn=1e7;
int n,a[maxn];
class Solution{
public:  
    int findLengthOfShortestSubarray(vector<int>& arr){
        n = arr.size();
        for(int i=1;i<=n;i++) a[i] = arr[i-1];
        int pre = 1;
        for(int i=2;i<=n;i++){
            if(a[i]>=a[i-1]) pre++;
            else break;
        }
        int suf = 1;
        for(int i =n-1;i>=0;i--){
            if(a[i]<=a[i+1]) suf++;
            else break;
        }
        if(pre==n) return 0;
        int ans = min(n-pre,n-suf);
        int r = n - suf + 1;
        for(int l=1;l<=pre;l++){
            for(;r<=n;r++) if(a[r]>=a[l]) break;
            int len = r - l -1;
            ans = min(ans,len);
        }
        return ans;
    }
};