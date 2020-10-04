#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        bool st[n + 1];
        int primes[n + 1], cnt = 0;
        memset(st, 0, sizeof st);
        for (int i = 2; i < n; i ++)
        {
            if(!st[i]) primes[cnt++] = i;
            for(int j =0;primes[j]<=n/i;j++){
                st[primes[j]*i] = true;
                if(i%primes[j]==0) break;
            }
        }
        return cnt;
    }
};
