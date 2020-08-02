#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 10;
int n,m;
int fa[maxn],val[maxn];
int a,b,s;


int find(int x){
    if(fa[x]==x) return x;
    int rt = find(fa[x]);
    val[x] += val[fa[x]];
    return fa[x] = rt;
}

void init(){
    for(int i =0;i<maxn;i++){
        fa[i] = i;
        val[i] = 0;
    }
}

int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        init();
        int ans =0 ;
        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&a,&b,&s);a--;
            int ta = find(a);
            int tb = find(b);
            if(ta!=tb){
                fa[tb] = ta;
                val[tb] = s + val[a] - val[b];
            }else{
                if(val[a]+s!=val[b]) ans++;
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}