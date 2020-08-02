#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 210,M = 210*210;
int h[2*N],e[M],ne[M];
int idx;
int n,m;
bool st[N*2];
int match[N*2];

void add(int a,int b){
    e[idx] = b;ne[idx] = h[a];h[a] = idx++;
}


bool dfs(int x){
    for(int i = h[x];i!=-1;i=ne[i]){
        int j = e[i];
        if(!st[j]){
            st[j] = true;
            if(!match[j] || dfs(match[j])){
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

int main(){
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof h);
    for(int i =1;i<=n;i++){
        int num;
        scanf("%d",&num);
        for(int j =1;j<=num;j++){
            int x;
            scanf("%d",&x);
            add(i,x+N);
        }
    }

    int res= 0;
    for(int i =1;i<=n;i++){
        memset(st,false,sizeof st);
        if(dfs(i)) res++;
    }
    cout<<res<<endl;

    return 0;
}