#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double Power(double base, int exponent) {
        bool neg = exponent < 0;
        exponent = abs(exponent);
        double res = 1;
        while(exponent){
            if(exponent & 1) res = res*base;
            base = base*base;
            exponent>>=1;
        }
        if(neg) return 1/res;
        return res;
    }
};