class Solution {
public:
    const int mod = 1337;
    int superPow(int a, vector<int>& b) {
        int size = b.size();
        int x = a % 1337;
        int res = 1;
        for (int i=size-1; i>=0; i--) {
            int pow = b[i];
            res = (res * mpow(x, pow))%1337;
            x = mpow(x, 10)%1337;
        }
        return res;
    }

    int mpow(int a,int b){
        int total = 1;
        int base = a;
        while(b){
            if(b&1) total *=base;
            total %= mod;
            b>>=1;
            base*=base;
            base %= mod;
        }
        return total % mod;
    }
};