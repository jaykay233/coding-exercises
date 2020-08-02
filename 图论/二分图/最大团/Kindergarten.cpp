//最大团等于求原图补图的最大独立集
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int N = 1010;
int mp[N][N];
int g,b,m;
bool used[N];
int match[N];
const int M = N * N /2;
int h[N],e[M],ne[M],idx;

void add(int a,int b){
    e[idx] = b;ne[idx] = h[a];h[a] = idx++;
}


bool dfs(int u){
    for(int i=h[u];i!=-1;i=ne[i]){
        int j = e[i];
        if(!used[j]){
            used[j] = true;
            if(!match[j] || dfs(match[j])){
                match[j] = u;
                return true;
            }
        }
    }
    return false;
}


int main(){
    int T = 0;
    while(scanf("%d%d%d",&g,&b,&m)==3 && (g || b || m)){
        T ++;
        memset(h,-1,sizeof h);
        memset(mp,0,sizeof mp);
        memset(used,false,sizeof used);
        memset(match,0,sizeof match);
        idx = 0;
        for(int i =1;i<=m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            mp[a][b] = 1;
            mp[b][a] = 1;
        }
        
        for(int i =1;i<=g;i++){
            for(int j =1;j<=b;j++){
                if(!mp[i][j]){
                    add(i,j);
                }
            }
        }

        int res = 0;
        for(int i =1;i<=g;i++){
            memset(used,false,sizeof used);
            if(dfs(i)) res++; 
        }
        int ans = g + b -res;
        printf("Case %d: %d\n",T,ans);
    }

    return 0;
}