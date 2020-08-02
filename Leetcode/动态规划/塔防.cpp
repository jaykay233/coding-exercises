#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int A,B,C,D,E;
int dp[2000][2000][2000]; //从i走到i+1,经过a个攻击塔，b个放毒塔,剩下个减速塔所收到的伤害
//攻击塔效果,防毒塔效果,减速塔效果

int main(){
    scanf("%d %d %d %d %d",&A,&B,&C,&D,&E);
    int max_val = 0;

    for(int i =1;i<=A;i++){
        for(int j =0 ;j<=i-1;j++){
            for(int k = 0;k<=i-1-j;k++){
                int m = i-1-j-k;
                if(m<0) continue;
                //进攻塔,放毒塔,减速塔
                dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k] + (k*C)*(E+m*D));
                dp[i][j+1][k] = max(dp[i][j+1][k],dp[i-1][j][k] + (B+k*C)*(E+m*D));
                dp[i][j][k+1] = max(dp[i][j][k+1],dp[i-1][j][k] + (k*C)*(E+m*D));
                max_val = max(max_val, dp[i][j][k]);
                max_val = max(max_val, dp[i][j+1][k]);
                max_val = max(max_val, dp[i][j][k+1]);
            }
        }
    }
    cout<<max_val<<endl;
    return 0;    
}

