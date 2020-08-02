#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 100010;
int f[N];
int sz[N];
void init(){
    for(int i =0;i<N;i++){
        f[i] = i;
        sz[i] = 1;
    }
}

int find(int a){
    if(f[a]==a) return a;
    return f[a] = find(f[a]);
}

void merge(int a,int b){
    int fa = find(a);
    int fb = find(b);
    if(fa == fb) return;
    if(sz[fa] > sz[fb]){
        f[fa] = fb;
        sz[fb] += sz[fa];
    }else{
        f[fb] = fa;
        sz[fa] += sz[fb];
    }
}


int main(){
    int a,b;
    while(cin>>n){
        init();
        for(int i =1;i<=n;i++){
            scanf("%d%d",&a,&b);
            merge(a,b);
        }
        int value = 0;
        for(int i =0;i<N;i++){
            value = max(value,sz[i]);
        }
        printf("%d\n",value);
    }

    return 0;
}