#include <iostream>
#include <cstdio>
using namespace std;
int n, k;
const int N = 100;
char chess[N][N];
int cnt =0 ;
bool row[N];
bool col[N];

void dfs(int x,int y,int m ){
    if(x==n) return;
    if(m==k){
        cnt++;
        return;
    }
    if(y==n){
        y = 0;
        x ++;
    }
    dfs(x,y+1,m);
    if(!row[x] && !col[y] && chess[x][y]=='#'){
        row[x] = col[y] = true;
        dfs(x,y+1,m+1);
        row[x] = col[y] = false;
    }
}


int main(){
    while(true){
        scanf("%d%d",&n,&k);
        if(n==-1 && k==-1) break;
        for(int i=0;i<n;i++){
            scanf("%s",chess[i]);
        }
        cnt = 0;
        dfs(0,0,0);
        printf("%d\n",cnt);
    }

    return 0;
}