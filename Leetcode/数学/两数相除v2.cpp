class Solution {
public:
    int divide(int d1, int d2) {
        long long dividend = d1;
        long long divisor = d2;
        bool ok = ((dividend>0 && divisor>0) || (dividend<0 && divisor<0)) ? true: false;
        dividend = abs(dividend);
        divisor = abs(divisor);
        long long total = 0;
        while(dividend >= divisor){
            long long s_divisor = divisor;
            long long sub = 1;
            while(dividend >= s_divisor){
                dividend -= s_divisor;
                total += sub;
                s_divisor *= 2;
                sub *= 2;
            }
        }
        if(!ok)
            return -1.0*total;
        return min(total,(long long)INT_MAX);
    }
};