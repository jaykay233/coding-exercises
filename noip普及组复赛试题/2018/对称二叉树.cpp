#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int siz[N],v[N],l[N],r[N],ans;

bool check(int r1,int r2){
    if(v[r1]!=v[r2]) return false;
    else if(r1==r2==0) return true;
    else return check(l[r1],r[r2]) && check(r[r1],l[r2]);
}

int dfs1(int rt){
    if(!rt) return 0;
    return siz[rt] = dfs1(l[rt]) + dfs1(r[rt]) + 1;
}

int dfs2(int rt){
    if(!rt) return 0;
    if(siz[l[rt]] == siz[r[rt]])
        if(check(l[rt],r[rt])) ans = max(ans,siz[rt]);
    dfs2(l[rt]);
    dfs2(r[rt]);
}


int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&v[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d%d",&l[i],&r[i]);
        if(l[i]==-1) l[i] = 0;
        if(r[i]==-1) r[i] = 0;
    }
    dfs1(1),dfs2(1);
    printf("%d",ans);

    return 0;
}