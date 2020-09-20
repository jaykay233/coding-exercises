#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
class Solution{
public:  

    int getCnt(long sum[],int n,int x){
        int res =0 ;
        for(int i =0,p=1;i<n;i++){
            while(p<=n && sum[p]-sum[i]<=x) p++;
            res+=p-i-1;
        }
        return res;
    }

    int getKth(long sum[],int n,int idx){
        int l = 0, r = 1e5;
        while(l<r){
            int m = l + r >>1, cnt = getCnt(sum,n,m);
            if(cnt<idx) l = m + 1;
            else r = m;
        }
        return l;
    }

    int F(long sum[],long ssum[],int n,int x){
        long num = getKth(sum,n,x),res=0,cnt=0;
        for(int i=0,p=1;i<n;i++){
            while(p<=n && sum[p]-sum[i]<=num) p++;
            res+=ssum[p-1]-ssum[i] - sum[i] * (long long)(p-1-i);
            cnt += p-1-i;
        }
        return res + (x-cnt) * num;
    }

    int rangeSum(vector<int>& nums,int n,int left,int right){
        long sum[n+1];
        sum[0] = 0;
        for(int i =1;i<=n;i++) sum[i] = sum[i-1] + nums[i-1];
        long ssum[n+1];
        for(int i=1;i<=n;i++) ssum[i] = ssum[i-1] + sum[i+1];

        return (F(sum,ssum,n,right) - F(sum,ssum,n,left-1)) % mod;
    }
};