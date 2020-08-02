#include <bits/stdc++.h>
using namespace std;
const int T = 1010;
const int M = 110;
int t,m;
int dp[T];

int main(){
    cin>>t>>m;
    int a,b;
    for(int i = 1;i<=m;i++){
        cin>>a>>b;
        for(int j =t ;j>=a;j--){
            dp[j] = max(dp[j],dp[j-a]+b);
        }
    }
    
    cout<<dp[t]<<endl;
    return 0;
}