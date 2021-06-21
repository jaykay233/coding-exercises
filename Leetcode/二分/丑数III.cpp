class Solution {
public:
    long gcd(long a,long b){
        return b == 0?a:gcd(b,a%b);
    }

    long lcm(long a,long b){
        return a/gcd(a,b) * b;
    }

    int nthUglyNumber(int n, int a, int b, int c) {
        long la = a;
        long lb = b;
        long lc = c;
        long lab = lcm(la,lb);
        long lac = lcm(la,lc);
        long lbc = lcm(lb,lc);
        long labc = lcm(lab,lc);

        long l = 0;
        long r = 2e9;
        long num = 0;
        while(l<r){
            long mid = l + r>>1;
            long sum = mid / la + mid / lb + mid / lc - mid/lab - mid/lac - mid/lbc + mid/labc;
            
            if(sum>=n){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }
};