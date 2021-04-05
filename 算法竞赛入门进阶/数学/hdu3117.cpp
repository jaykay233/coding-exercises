#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
 
using namespace std;
 
//typedef long long ll;
typedef long long ll;
 
const int MOD = 10000;
 
struct mat{
    ll s[2][2];
    mat(ll a = 0, ll b = 0, ll c = 0, ll d = 0) {
        s[0][0] = a;
        s[0][1] = b;
        s[1][0] = c;
        s[1][1] = d;
    }
    mat operator * (const mat& c) {
        mat ans; 
        memset(ans.s, 0, sizeof(ans.s));
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++) {
                    ans.s[i][j] = (ans.s[i][j] + s[i][k] * c.s[k][j]);
                    if (ans.s[i][j] >= 100000000)
                        ans.s[i][j] %= MOD;
                }
        return ans;
    }
}c(1, 1, 1, 0), tmp(1, 0, 0, 1);
 
ll n;
 
mat pow_mod(ll k) {
    if (k == 0) 
        return tmp;
    else if (k == 1)
        return c;
    mat a = pow_mod(k / 2);
    mat ans = a * a;
    if (k % 2)
        ans = ans * c;
    return ans;
}
 
int main() {
    while (scanf("%I64d", &n) != EOF) {
        if (n == 0) 
            printf("0\n");
        else {
            mat ans = pow_mod(n - 1); 
            if (n >= 40) {
                double k = log10(1.0 / sqrt(5.0)) + (double)n * log10((1.0 + sqrt(5.0)) / 2.0);
                double temp = k;
                temp = k - (int)temp;
                printf("%d...%.4I64d\n", (int)(1000.0 * pow(10.0, temp)), ans.s[0][0] % MOD);
            }
            else 
                printf("%I64d\n", ans.s[0][0]);
        }
    } 
    return 0;
}
