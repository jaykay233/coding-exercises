#include <bits/stdc++.h>
using namespace std;
const int M = 2e5+10;

struct Node{
    int l,r;
    int max_;
}tr[M<<2];

void build(int u,int l,int r){
    tr[u].l = l;
    tr[u].r = r;
    if(l==r){
        return;
    }
    int mid = (l + r) >>1;
    build(u<<1, l ,mid);
    build(u<<1|1,mid+1,r);
    return;
}

void pushup(int u){
    tr[u].max_ = max(tr[u<<1].max_, tr[u<<1|1].max_);
}

void modify(int u,int x,int w){
    if(tr[u].l == x && tr[u].r == x){
        tr[u].max_ = w;
    }else{
        int mid = (tr[u].l + tr[u].r)>>1;
        if(x<=mid) modify(u<<1,x,w);
        else modify(u<<1|1,x,w);
        pushup(u);
    }
}

int query(int u,int l,int r){
    if(l<=tr[u].l && tr[u].r<=r){
        return tr[u].max_;
    }else{
    int mid = (tr[u].l + tr[u].r)>>1;
    if(r<=mid) return query(u<<1,l,r);
    else if(l>mid)  return query(u<<1|1,l,r);
    else{
            int le = query(u<<1, l, mid);
            int re = query(u<<1|1,mid+1,r);
            return max(le,re);
        }
    }
}

int main()
{
    int m,p;
    int n = 0, last = 0;
    scanf("%d%d", &m, &p);
    build(1, 1, m);

    int x;
    char op[2];
    while (m -- )
    {
        scanf("%s%d", op, &x);
        if (*op == 'Q')
        {
            last = query(1, n - x + 1, n);
            printf("%d\n", last);
        }
        else
        {
            modify(1, n + 1, (last + x) % p);
            n ++ ;
        }
    }

    return 0;
}

 