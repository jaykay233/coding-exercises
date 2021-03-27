//三进制状压
//https://vjudge.net/problem/HDU-3001
#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int n,m;
int bit[12]={0,1,3,9,27,81,243,729,2187,6561,19683,59049};
int tri[60000][11];
int dp[11][60000];
int graph[11][11];

void make_trb(){
    for(int i=0;i<59050;i++){
        int t = i;
        for(int j=1;j<=10;j++){
            tri[i][j] = t%3;
            t/=3;
        }
    }
}

int comp_dp(){
    int ans = INF;
    memset(dp,INF,sizeof dp);
    for(int i =0;i<=n;i++){
        dp[i][bit[i]] = 0;
    }
    for(int i =0;i<bit[n+1];i++){
        int flag = 1;
        for(int j=1;j<=n;j++){
            if(tri[i][j]==0){
                flag =0 ;
                continue;
            }
            if(i==j) continue;
            for(int k=1;k<=n;k++){
                int l = i - bit[j];
                if(tri[i][k]==0) continue;
                dp[j][i] = min(dp[j][i],dp[k][l] + graph[k][j]);
            }
        }
        if(flag)
                for(int j=1;j<=n;j++)
                    ans = min(ans,dp[j][i]);
    }
    return ans;
}

int main(){
    make_trb();
    while(cin>>n>>m){
        memset(graph,INF,sizeof graph);
        while(m--){
            int a,b,c;
            cin>>a>>b>>c;
            if(c<graph[a][b]) graph[a][b] = graph[b][a] = c;
        }
        int ans = comp_dp();
        if(ans==INF) cout<<"-1"<<endl;
        else cout<<ans<<endl;
    }

    return 0;
}