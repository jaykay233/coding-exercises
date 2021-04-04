/**
 * hdu5392 Infoplane in Tina Town
 * LCM + 快速幂取模
 */

#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long LL;

LL fastPow(LL a, LL b, LL mod = LLONG_MAX)
{
    a %= mod;
    LL t = 1;
    while (b) {
        if (b&1) t = t*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return t%mod;
}

LL mod = 3221225473LL;

void counting(int n, vector<int>& num)
{
    for (int i = 2; i*i <= n; ++i) {
        int cnt = 0;
        while (n%i == 0) n /= i, ++cnt;
        num[i] = max(num[i], cnt);
    }
    if (n != 1) num[n] = max(num[n], 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> A(n+1), num(n+1);
        vector<bool> vis(n+1);
        for (int i = 1; i <= n; ++i) cin >> A[i];
        for (int i = 1; i <= n; ++i) {
            if (vis[i]) continue;
            int cnt = (A[i] != i);
            int p = i;
            while (A[p] != i) p = A[p], vis[p] = 1, ++cnt;
            counting(cnt, num);
        }
        LL ans = 1;
        for (int i = 2; i <= n; ++i) {
            ans *= fastPow(i, num[i], mod);
            ans %= mod;
        }
        if (ans == 1) ans = 0;
        cout << ans << endl;
    }
    return 0;
}
