#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll dp[21][3];
int num[20];
int len =0 ;
int digits[21];
//dp[i][0]表示长度为i但不包含49的数据的个数
//dp[i][1]表示长度为i但不包含49，并且第i位为49的数据的个数
//dp[i][2]表示长度为i且包含49的所有数据的个数
int main(){
    dp[0][0] = 1;
    for(int i=1;i<20;i++){
        dp[i][0] = dp[i-1][0] * 10 - dp[i-1][1];
        dp[i][1] = dp[i-1][0];
        dp[i][2] = dp[i-1][2]*10 + dp[i-1][1];
    }

    int t;
    ll n ;
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);
        memset(num,0,sizeof num);
        int len = 0;
        while(n){
            num[++len] = n%10;
            n/=10;
        }
        bool flag = false;
        ll ans =0, last =0 ;
        for(int i=len;i>=1;i--){
            ans += dp[i-1][2] * num[i];
            if(flag){
                ans += dp[i-1][0] * num[i];
            }
            if(flag==0 && num[i]>=4){
                ans += dp[i-1][1];
            }
            if(last==4 && num[i]==9){
                flag = true;
            }
            last = num[i];
        }
        printf("%lld\n",ans);
    }

    return 0;
}