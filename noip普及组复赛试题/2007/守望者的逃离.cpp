//线性dp 贪心 + 动态规划
#include <bits/stdc++.h>
using namespace std;
const int T = 300010;
int dp[T];

int main(){
    int m,s,t;scanf("%d%d%d",&m,&s,&t);
    int dp[T];
    for(int i=1;i<=t;i++){
        if(m>=10){
            dp[i] = dp[i-1] + 60;
            m -= 10;
        }else{
            dp[i] = dp[i-1];
            m+=4;
        }
    }
    for(int i=1;i<=t;i++) dp[i] = max(dp[i],dp[i-1] + 17);
    int max_num =0;
    for(int i =1;i<=t;i++){
        if(dp[i] >= s) {
            cout<<"Yes"<<endl;
            cout<<i<<endl;
            return 0;
        }
        max_num = max(max_num,dp[i]);
    }
    
    cout<<"No"<<endl;
    cout<<max_num<<endl;
    
    
    return 0;
}