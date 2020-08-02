class Solution {
public:
    int digitAtIndex(int n) {
        long long i = 1,s = 9,base = 1;
        while(n>i*s){
            n -= i*s;
            i++;
            s*=10;
            base = base*10;
        }
        int number = base + (n+i-1)/i -1;
        int r = n%i ? n%i : i;
        for(int j=0;j<i-r;j++) number/=10;
        return number%10;
    }
};