//枚举所有不超过根号r的质数p，再枚举区间中【l,r】中的所有数，如果有超出根号r的质数，那么最多有1次，所以要判断一下
#include <iostream>
#include <stdio.h>
#include <string.h>
#define ll long long
using namespace std;

const int MAXN = 1e6 + 10;
const int mode = 998244353;
int prime[MAXN], tag[MAXN], tot;
ll sum[MAXN], gel[MAXN];

void get_prime(void){
    for(int i = 2; i < MAXN; i++){
        if(!tag[i]){
            prime[tot++] = i;
            for(int j = 2; j * i < MAXN; j++){
                tag[j * i] = 1;
            }
        }
    }
}

ll Max(ll a, ll b){
    return a > b ? a : b;
}

int main(void){
    get_prime();
    ll l, r;
    int k, t;
    scanf("%d", &t);
    while(t--){
        scanf("%lld%lld%d", &l, &r, &k);
        for(int i = 0; i <= r - l; i++){
            sum[i] = 1; //sum[i]记录i+l对答案的贡献
            gel[i] = i + l; //将所有元素放到a数组里
        }
        for(int i = 0; i < tot; i++){
            ll a = (l + prime[i] - 1) / prime[i] * prime[i];
            for(ll j = a; j <= r; j += prime[i]){ // 筛[l, r]内的合数
                ll cnt = 0;
                while(gel[j - l] % prime[i] == 0){
                    cnt++;
                    gel[j - l] /= prime[i];
                }
                sum[j - l] = sum[j - l] * (cnt * k + 1 % mode);
                if(sum[j - l] >= mode) sum[j - l] %= mode;
            }
        }
        ll sol = 0;
        for(int i = 0; i <= r - l; i++){
            if(gel[i] != 1) sum[i] = sum[i] * (k + 1);
            sol += sum[i];
            if(sol >= mode) sol %= mode;
        }
        printf("%lld\n", sol);
    }
    return 0;
}