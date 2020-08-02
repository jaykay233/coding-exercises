//最小点覆盖
#include <bits/stdc++.h>
using namespace std;
int n,m,k;
const int N = 110,M = 210;
int g[N][N];
int match[N];
bool st[N];

bool find(int x){
    for(int i =1;i<m;i++){
        if(st[i] || !g[x][i]) continue;
        st[i] = true;
        if(match[i]==-1 || find(match[i])) {
            match[i] = x;
            return true;
        }
    }
    return false;
}

int main(){
    while(cin>>n && n){
        scanf("%d%d",&m,&k);
        memset(g,0,sizeof g);
        memset(match,-1,sizeof match); 
        for(int i=0;i<k;i++){
            int idx,a,b;
            scanf("%d%d%d",&idx,&a,&b);
            if(a==0 || b==0) continue;
            g[a][b] = true;
        }

        long long res =0 ;

        for(int i =1;i<n;i++){
            memset(st,false,sizeof st );
            if(find(i)) res++;
        }

        cout<<res<<endl;
    }

    return 0;
}