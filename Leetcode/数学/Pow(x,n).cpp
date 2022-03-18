class Solution {
public:
    double myPow(double x, int n) {
        if(x==-1.0) return n%2 ? -1.0 : 1;
        bool signal = n>0?true:false;
        if (n < 0){
            if(n==INT_MIN)
                n = INT_MAX;
            else 
                n = -n;
        }
        double res = 1;
        while(n){
            if(n&1) res *= x;
            x *= x;
            n>>=1;
        }
        if(!signal) return 1.0/res;
        return res;
    }
};