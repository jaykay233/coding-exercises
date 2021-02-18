#include <bits/stdc++.h>
using namespace std;
const int maxn = 50000+5;

int n,q;
int s[maxn*4],e[maxn*4];
int prelen[maxn*4],suflen[maxn*4],maxlen[maxn*4];

void build(int o,int l,int r){
    s[o] = l;
    e[o] = r;
    prelen[o] = suflen[o] = maxlen[o] = r - l + 1;
    if(l==r) return;
    int m = l + r >> 1;
    build(o<<1,l,m);
    build(o<<1|1,m+1,r);
}

void pushup(int o){
    prelen[o] = prelen[o<<1];
    suflen[o] = suflen[o<<1|1];
    maxlen[o] = max(maxlen[o<<1],maxlen[o<<1|1]);
    maxlen[o] = max(maxlen[o],suflen[o<<1] + prelen[o<<1|1]);
    if(prelen[o<<1] == (e[o<<1] - s[o<<1] + 1)) prelen[o] += prelen[o<<1|1];
    if(suflen[o<<1|1] = (e[o<<1|1] - s[o<<1|1] + 1)) suflen[o] += suflen[o<<1];
}

void update(int o,int k,int v){
    if(s[o] ==k && e[o]==k){
        prelen[o] = suflen[o] = maxlen[o] = v;
        return;
    }
    if(s[o] == e[o]) return;
    int m = (s[o] + e[o]) >> 1;
    if(k<=m) update(o<<1,k,v);
    else update(o<<1|1,k,v);
    pushup(o);
}

int query(int o,int k){
    if(s[o] == e[o] || maxlen[o] == 0 || maxlen[o] == e[o] - s[o] + 1)
        return maxlen[o];
    int m = (s[o] + e[o]) >> 1;
    int lc = o<<1 , rc = o<<1|1;
    if(k<=m){
        if(k+suflen[o<<1]-1>=e[lc]) return suflen[lc] + prelen[rc];
        else return query(lc,k);
    }else{
        if(s[rc] + prelen[rc]-1>=k) return prelen[rc] + suflen[lc];
        else return query(rc,k);
    }
}



int main(){
    while(~scanf("%d%d",&n,&q)){
        build(1,1,n);
        char op;
        int a;
        stack<int> village;
        if(op=='D'){
            scanf("%d",&a);
            village.push(a);
            update(1,a,0);
        }
        if(op=='Q'){
            scanf("%d",&a);
            printf("%d\n",query(1,a));
        }
        if(op=='R'){
            if(!village.empty()){
                a = village.top();
                village.pop();
                update(1,a,1);
            }
        }
    }

    return 0;
}