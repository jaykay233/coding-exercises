// abcdef
// ab1def
// 0 - ab-1 : 0 - 999
// ab:
//分情况讨论
// c = 0 0
// c = 1 + def 
// c > 1 0-999
//复习数位dp
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOf1Between1AndN_Solution(int n) {
        vector<int> digits;
        while(n) {
            digits.push_back(n%10);
            n/=10;
        }
        int len = digits.size();
        int res =0 ;
        for(int i =digits.size()-1;i>=0;i--){
            int left =0 , right = 0,t = 1;
            for(int j =digits.size()-1;j>i;j--) left = left*10+digits[j];
            for(int j =i-1;j>=0;j--) right = right*10+digits[j],t*=10;
            res+=left*t;
            if(digits[i]==1) res+=right+1;
            else if(digits[i]>1) res+=t;
        }
        return res;
    }
};