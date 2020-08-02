#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int f[N],sum[N];
int n,m;

void init(){
    for(int i =0;i<N;i++){
        f[i] = i;
        sum[i] = 0;
    }
}

int find(int x){
    if(f[x]==x) return f[x];
    int rt = find(f[x]);
    sum[x] += sum[f[x]];
    return f[x] = rt;
}

int main(){
    while(~scanf("%d%d",&n,&m)){
        int output =0 ;
        init();
        for(int i =0;i<m;i++){
            int x,y,w;
            scanf("%d%d%d",&x,&y,&w);
            int xx =find(x);
            int yy = find(y);
            if(xx == yy){
                if(sum[y]-sum[x]!=w){
                    output++;
                }
            }else{
                sum[yy] = w - sum[y] + sum[x];
                f[yy] = xx;
            }
        }
        printf("%d\n",output);
    }
    return 0;
}