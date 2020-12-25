class Solution {
public:
    int countVowelPermutation(int n) {
        int a,e,i,o,u;

        if(n == 1)return 5;
        a = e = i = o = u = 1;

        const int mod = 1e9 + 7;

        for(int j = 2; j <= n; j++){
            int aa, ee, ii, oo, uu;

            aa = ((e + i) % mod + u) % mod;
            ee = (a + i) % mod;
            ii = (e + o) % mod;
            oo = i;
            uu = (i + o) % mod;
            
            a = aa, e = ee, i = ii, o = oo, u = uu;
            //printf("%d %d %d %d %d\n",a,e,i,o,u);
        }

        return ((long long) a + e + i + o + u) % mod;
    }
};
