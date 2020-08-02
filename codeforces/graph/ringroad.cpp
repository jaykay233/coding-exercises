#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int g[N][N];
int n;
int ans = 1e9;
int cur = 0;

void dfs(int x,int sum,int fa){
    if(x==1){
        cur++;
        if(cur>1){
            ans = min(ans,sum);
            return;
        }
    }
    for(int i=1;i<=n;i++){
        if(i == fa) continue;
        if(g[x][i]){
            dfs(i,sum,x);
        }else if(g[i][x]){
            dfs(i,sum+g[i][x],x);
        }
    }
}

int main(){
    scanf("%d",&n);
    for(int i =1;i<=n;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        g[a][b] = c;  
    }
    dfs(1,0,-1);
    cout<<ans<<endl;
    return 0;
}