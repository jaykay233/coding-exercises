#include <bits/stdc++.h>
using namespace std;
int idx;
const int N = 2e5+10;
int e[N],h[N],ne[N];
int ans =0 ;

void add(int a,int b){
    e[idx] = b;ne[idx] = h[a];h[a] = idx++;
}


int dfs(int u,int f){
    int res = 1;
    for(int i =h[u];i!=-1;i=ne[i]){
        int j = e[i];
        if(j==f) continue;
        res += dfs(j,u);
    }
    return res;
}

int main(){
    memset(h,-1,sizeof h);
    int n;
    cin>>n;
    for(int i =1;i<=n-1;i++){
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    for(int i = h[1];i!=-1;i=ne[i]){
        ans = max(ans,dfs(e[i],1));
    }
    cout<<ans<<endl;
    return 0;
}