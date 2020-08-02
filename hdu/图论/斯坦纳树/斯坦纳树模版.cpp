#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
const int inf = 0x3f3f3f3f;
int n,m;
int dis[maxn][maxn];
int dp[1<<10][maxn];
vector<pair<int,int>> neigh;
void spfa(){
    int inq[maxn] = {0};
    for(int s =1;s<=n+m;s++){
        for(int j =1;j<=n+m;j++)
            dis[s][j] = inf;
        dis[s][s] = 0;
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            int t= q.front();q.pop();
            inq[t] = 0;
            for(pair<int,int> p:neigh){
                int v = p.first;
                int w = p.second;
                if(dis[s][v] > dis[s][t] + w){
                    dis[s][v] = dis[s][t] + w;
                    if(!inq[v]){
                        inq[v] = 1;
                        q.push(v);
                    }
                }
            }
        }
    }
}

void dp(){
    for(int state=1;state<(1<<n+1);state++){
        for(int i =0;i<=n+m;i++){
            dp[state][i] = inf;
        }
    }

    for(int i =0;i<=n;i++){
        for(int j =0;j<=n+m;j++){
            dp[(1<<i)][j] = dis[i][j];
        }
    }

    for(int state=1;state<(1<<n+1);state++){
        if(state & (state-1)){
            for(int i =0;i<=n+m;i++){
                for(int sub = state-1;sub>0;sub = (sub-1)& state){
                    dp[state][i] = min(dp[state][i],dp[state^sub][i] + dp[sub][i]);    
                }   
            }
            for(int i =0;i<=n+m;i++){
                for(int j =0;j<=n+m;j++){
                    dp[state][i] = min(dp[state][i],dp[state][j]+dis[j][i]);
                }
            }

        }
    }


}


int main(){
    return 0;
}