#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N = 500000+10;
int a[N];

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

struct Node{
    int l,r;
    int sum;
    int g;
}tr[N<<2];

void pushup(int u){
    tr[u].sum = tr[u<<1].sum + tr[u<<1|1].sum;
    tr[u].g = gcd(tr[u<<1].g,tr[u<<1|1].g);
}


void build(int u,int l,int r){
    tr[u].l = l;
    tr[u].r = r;
    if(l==r){
        tr[u].sum = a[r];
        tr[u].g = a[r];
        return;
    }
    int mid = (l+r)>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int x,int y){
    if(tr[u].l == x && tr[u].r == x){
        int b = tr[u].sum;
        tr[u].sum = b + y;
        tr[u].g = b + y;
        return;
    }
    int mid = (tr[u].l + tr[u].r) >>1;
    if(x<=mid) modify(u<<1,x,y);
    else modify(u<<1|1,x,y);
    pushup(u);
}

Node query(int u,int l,int r){
    if(l<=tr[u].l && tr[u].r<=r){
        return tr[u];   
    }else{
        int mid = (tr[u].l + tr[u].r)>>1;
        if(r<=mid) return query(u<<1,l,r);
        else if(l>mid) return query(u<<1|1,l,r);
        Node left = query(u<<1,l,r);
        Node right = query(u<<1|1,l,r);
        Node res;
        res.sum = left.sum + right.sum;
        res.g = gcd(left.g,right.g);
        pushup(u);
    }
    return {};
}






int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=n;i>=1;i--) a[i] -= a[i-1];

    for(int i=1;i<=m;i++){
        char op[2];
        scanf("%s",op);
        int l,r,d;
        if(op[0]=='Q'){
            scanf("%d%d",&l,&r);
            auto left = query(1,1,l), right = query(1,l+1,r);
            printf("%lld\n",abs(gcd(left.sum,right.d)));
        }else if(op[0]=='C'){
            scanf("%d %d %d",&l,&r,&d);
            modify(1,l,d);
            if(r+1<=n) modify(1,r+1,-d);
        }
    }

    return 0;
}