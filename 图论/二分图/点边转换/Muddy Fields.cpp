//对点进行编号后 二分图
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int N = 60;
const int M = 60;
const int C = N * M;
char g[N][M];
int row[N][M];
int col[N][M];
int n,m;
int match[C*2];
int idx;
int h[C*2],e[C*2],ne[C*2];
bool st[C*2];

void add(int a,int b){
    e[idx] = b;ne[idx] = h[a];h[a] = idx++;
}

bool dfs(int u){
    for(int i=h[u];i!=-1;i=ne[i]){
        int j = e[i];
        if(!st[j]){
            st[j] = true;
            if(match[j]==-1 || dfs(match[j])){
                match[j] = u;
                return true;
            }
        }
    }
    return false;
}


int main(){
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof h);
    memset(match,-1,sizeof match);
    for(int i =0;i<n;i++){
        scanf("%s",g[i]);
    }
    int cnt =0 ;
    for(int i=0;i<n;i++){
        int j =0;
        while(j<m){
            while(j<m && g[i][j]!='*') j++;
            if(j<m) {
                cnt++;
                while(j<m && g[i][j]=='*') {
                    row[i][j] = cnt;
                    j++;
                }
            }    
        }
    }

    cnt = 0;
    for(int i =0;i<m;i++){
        int j = 0;
        while(j<n){
            while(j<n && g[j][i]!='*') j++;
            if(j<n){
                cnt++;
                while(j<n && g[j][i]=='*'){
                    col[j][i] = cnt;
                    j++;
                }
            }
        }
    }

    int maxnum = 0;
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(g[i][j]=='*'){
                int x = row[i][j];
                int y = col[i][j];
                maxnum = max(maxnum,x);
                add(x,C+y);
            }
        }
    }
    
    int res= 0;
    for(int i =1;i<=maxnum;i++){
        memset(st,false,sizeof st);
        if(dfs(i)) res++;
    }

    cout<<res<<endl;

    return 0;
}