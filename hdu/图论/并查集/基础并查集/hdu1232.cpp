#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int f[N];

void init(){
    for(int i =0;i<N;i++) f[i] = i;
}

int find(int a){
    if(a==f[a]) return a;
    return f[a] = find(f[a]);
}

int main(){
    int m,n;
    while(scanf("%d",&m) && m){
        scanf("%d",&n);
        init();
        int k = 0;
        for(int i =1;i<=n;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            int fa = find(a);
            int fb = find(b);
            if(fa==fb) continue;
            else{
                k++;
                f[fa] = fb;
            }
        }
        printf("%d\n",m-1-k);
    }

    return 0;
}