#include <bits/stdc++.h>
using namespace std;
int dp[105][105];

int val[5][5]={
    5,-1,-2,-1,-3,
    -1,5,-3,-2,-4,
    -2,-3,5,-2,-2,
    -1,-2,-2,5,-1,
    -3,-4,-2,-1,-5
};

char s1[105],s2[105];

int change(char x){
    if(x=='A') return 0;
    if(x=='C') return 1;
    if(x=='G') return 2;
    if(x=='T') return 3;
    if(x==' ') return 4;
}

int max_(int a,int b,int c){
    return max(a,max(b,c));
}

int main(){
    int t,l1,l2,i,j;
    scanf("%d",&t);
    getchar();
    scanf("%s",s1+1);
    scanf("%d",&l2);
    getchar();
    scanf("%s",s2+1);
    memset(dp,0,sizeof dp);
    for(i=1;i<=l1;i++)
        dp[i][0] = dp[i-1][0] + val[change(s1[i])][change(' ')];
    for(i=1;i<=l2;i++)
        dp[0][i] = dp[0][i-1] + val[change(s2[i])][change(' ')];
    for(i=1;i<=l1;i++)
        for(j=1;j<=l2;j++)
            dp[i][j] = max_(dp[i-1][j-1] + val[change(s1[i])][change(s2[j])],
            dp[i-1][j] + val[change(s1[i])][change(' ')],
            dp[i][j-1] + val[change(s2[j])][change(' ')]);

    return 0;
}