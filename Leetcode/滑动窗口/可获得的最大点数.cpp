#include <bits/stdc++.h>
using namespace std;
class Solution{
public:  
    int maxScore(vector<int>& cardPoints,int k){
        int n = cardPoints.size();
        int windowSize = n - k;
        int sum = accumulate(cardPoints.begin(),cardPoints.end() + windowSize,0);
        int ans = sum;
        for(int i =windowSize;i<n;i++){
            sum += cardPoints[i] - cardPoints[i-windowSize];
            ans = min(ans,sum);
        }
        return accumulate(cardPoints.begin(),cardPoints.end(),0) - ans;
    }
};