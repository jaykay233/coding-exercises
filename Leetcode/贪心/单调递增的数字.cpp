#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        vector<int> digits;
        while(n){
            digits.push_back(n%10);
            n/=10;
        }
        reverse(digits.begin(),digits.end());
        for(int i = digits.size()-1;i>=0;i--){
            if(i+1>=digits.size() || digits[i] <= digits[i+1]) continue;
            int j = i;
            digits[j++]--;
            while(j<digits.size()){
                digits[j] = 9;
                j++;
            }
        }
        int res =0 ;
        for(int r:digits){
            res = res * 10 + r;
        }
        return res;
    }
};