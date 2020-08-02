#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long gcd(long long a,long long b){
        return b==0?a:gcd(b,a%b);
    }
    
    long long gcm(long long a,long long b){
        return a/gcd(a,b)*b;
    }
    
    
    int nthUglyNumber(int n, int a, int b, int c) {
        long long l = 0, r = 2e9;
        while(l<r){
            int m = l + r>>1;
            int sum = m/a + m/b + m/c - m/gcm(a,b) - m/gcm(a,c) - m/gcm(b,c) + m/gcm(a,gcm(b,c));
            if(sum < n) l = m + 1;
            else r = m;
        }
        return l;
    }
};

int main(){
    

    return 0;
}