#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
struct Node{
    int l,r;
    int sum;
    int max;
    int lmax;
    int rmax;
}tr[N<<2];

void pushup(int u){
    tr[u].sum = tr[u<<1].sum + tr[u<<1|1].sum;
    tr[u].lmax = max(tr[u<<1].lmax, tr[u<<1].sum + tr[u<<1|1].lmax);
    tr[u].rmax = max(tr[u<<1|1].rmax,tr[u<<1|1].sum + tr[u<<1].rmax);
    tr[u].max = max(tr[u].max ,max(tr[u].lmax,tr[u].rmax));
    tr[u].max = max(tr[u].max , max(tr[u<<1].max,tr[u<<1|1].max));
    tr[u].max = max(tr[u].max, max(tr[u<<1].rmax,0) + max(tr[u<<1|1].lmax,0));
}

void build(int u,int l,int r){
    tr[u].l = l;
    tr[u].r = r;
    if(l==r){
        int a;
        scanf("%d",&a);
        tr[u].sum = a;
        tr[u].max = a;
        tr[u].lmax = a;
        tr[u].rmax = a;
        return;
    }
    int mid = (l + r) >>1;
    build(u<<1,l,mid);
    build(u<<1|1, mid + 1,r);
    pushup(u);
}

void modify(int u,int x,int y){
    if(tr[u].l == x && tr[u].r == x){
        tr[u].sum = y;
        tr[u].lmax = y;
        tr[u].rmax = y;
        tr[u].max = y;
        return;
    }
    int mid = (tr[u].l + tr[u].r) >> 1;
    if(x<=mid) modify(u<<1,x,y);
    else modify(u<<1|1,x,y);
    pushup(u);
}

int query(int u,int l,int r){
    if(l<=tr[u].l && tr[u].r<=r){
        return tr[u].max;
    }
    int mid = (tr[u].l + tr[u].r)>>1;
    if(r<=mid) return query(u<<1,l,r);
    else if(l>mid) return query(u<<1|1,l,r);
    int le = query(u<<1,l,r);
    int re = query(u<<1|1,l,r);
    int me = max(tr[u<<1].rmax,0) + max(tr[u<<1|1].lmax,0);
    return max(le,max(re,me));
}


int main(){
    int n,m;
    cin>>n>>m;
    build(1,1,n);
    for(int i=1;i<=m;i++){
        int k,x,y;
        scanf("%d %d %d",&k,&x,&y);
        if(k==1){
            if(x>y) swap(x,y);
            printf("%d\n",query(1,x,y));
        }else{
            if(x>y) swap(x,y);
            modify(1,x,y);
        }
    }
    return 0;
}