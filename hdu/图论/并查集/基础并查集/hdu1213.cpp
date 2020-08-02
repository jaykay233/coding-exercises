#include <bits/stdc++.h>
using namespace std;
int c;
const int M = 1010;
int f[M];

void init(){
    for(int i=1;i<M;i++){
        f[i] = i;
    }
}

int find(int a){
    if(f[a] ==a) return a;
    return f[a] = find(f[a]);
}


int main(){
    scanf("%d",&c);
    for(int i=1;i<=c;i++){
        init();
        int n,m;
        int ans =0 ;
        scanf("%d%d",&n,&m);
        for(int i =1;i<=m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            int u = find(a);
            int v = find(b);
            if(u!=v) {
                f[u] = v;
                ans++; 
            }
        }
        printf("%d\n", n -ans);
    }

    return 0;
}