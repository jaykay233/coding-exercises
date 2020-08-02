#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N = 1e5+10;

struct Node{
    int l,r,sum,add;
}tr[N<<2];

void pushdown(int u){
    tr[u<<1].sum += tr[u].add * (tr[u<<1].r - tr[u<<1].l + 1);
    tr[u<<1|1].sum += tr[u].add * (tr[u<<1|1].r - tr[u<<1|1].l + 1);
    tr[u<<1].add += tr[u].add;
    tr[u<<1|1].add += tr[u].add;
    tr[u].add = 0;
}

int query(int u,int l,int r){
    if(l<=tr[u].l && tr[u].r<=r){
        return tr[u].sum;
    }else{
        pushdown(u);
        int mid = (tr[u].l + tr[u].r)>>1;
        int res =0;
        if(l<=mid) res+=query(u<<1,l,r);
        if(r>mid) res+=query(u<<1|1,l,r);
        return res;
    }
}

void pushup(int u){
    tr[u].sum = tr[u<<1].sum + tr[u<<1|1].sum;
}


void modify(int u,int l,int r,int d){
    if(l<= tr[u].l && tr[u].r <=r){
        tr[u].sum += d*(tr[u].r - tr[u].l+1);
        tr[u].add += d;
    }else{
        pushdown(u);
        int mid = (tr[u].l + tr[u].r) >>1;
        if(l<=mid) modify(u<<1,l,r,d);
        if(r>mid) modify(u<<1|1,l,r,d);
        pushup(u);
    }
}


int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++){
        char op[2];
        scanf("%s",op);
        if(op[0]=='Q'){
            int l,r;
            printf("%d\n",query(1,l,r));
        }else if(op[0]=='C'){
            int l,r,d;
            scanf("%d%d%d",&l,&r,&d);
            modify(1,l,r,d);
        }
    }

    return 0;
}