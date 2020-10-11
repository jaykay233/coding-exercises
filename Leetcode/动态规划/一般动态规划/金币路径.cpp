#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> cheapestJump(vector<int>& A, int B) {
        int n = A.size();
        vector<int> next(n,-1);
        vector<long> dp(n);
        vector<int> res;
        for(int i = A.size()-2;i>=0;i--){
            long min_cost = INT_MAX/2;
            for(int j = i+1;j<=i+B && j<A.size();j++ ){
                if(A[j]<0) continue;
                long cost = A[i] + dp[j];
                if(min_cost > cost){
                    min_cost = cost;
                    next[i] = j;
                }
            }
            dp[i] = min_cost;
        }
        int i;
        for (i = 0; i < A.size() && next[i] > 0; i = next[i])
            res.push_back(i + 1);
        if (i == A.size() - 1 && A[i] >= 0)
            res.push_back(A.size());
        else
            return {};
        return res;
    }
};


for(int i =0;i<nums.size()-k+1;i++){
            while(j<nums.size() && count<k) {
                add(maxheap,minheap,nums[i]);
                count++;
                j++;
            }
            if(count==k){
                if(maxheap.size() == minheap.size()){
                    res.push_back((maxheap.top() + minheap.top())*1.0/2 );
                }else{
                    res.push_back(maxheap.top());
                }
            }
            count--;
            remove(maxheap,minheap,(double)nums[i]);
        }