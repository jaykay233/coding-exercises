#include <bits/stdc++.h>
using namespace std;
int T,N,M;
const int MAXN = 110;
int item[MAXN][MAXN];
vector<pair<int,int>> v;
const int MAXM = 1e4+10;
int dp[MAXM];

int main(){
    scanf("%d%d%d",&T,&N,&M);
    for(int i =0;i<T;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&item[i][j]);
        }
    }
    
    for(int i =0;i<T-1;i++){
        memset(dp,0,sizeof dp);
        for(int j =0 ;j<N;j++){
            if(item[i+1][j] > item[i][j]){
                for(int k =item[i][j];k<=M;k++){
                    dp[k] = max(dp[k],dp[k-item[i][j]] + item[i+1][j] - item[i][j]);
                }
            }    
        }
        M+=dp[M];
    }
    
    cout<<M<<endl;
    
    
    return 0;
}