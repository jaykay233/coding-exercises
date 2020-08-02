//放弃吧，少年，此题应用cdq分治
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cctype>
using namespace std;
const int maxn = 5e5+10;
const int INF = 0x3f3f3f3f;
int n,m,dim,ans,root,cnt;

struct Point{
    int x[2];
    Point(int a=0,int b=0){x[0]=a;x[1]=b;}
    inline int& operator[](int i){return x[i];}
    inline bool operator <(const Point& T)const {return x[dim]<T.x[dim];}
}p[maxn];

struct KD_Tree{
    int l,r;
    int mx[2],mi[2];
    Point t;
}tr[maxn<<1];

#define mid ((l+r)>>1)

void pushup(int k){
    tr[k].mx[0] = max(tr[k].mx[0],max(tr[tr[k].l].mx[0],tr[tr[k].r].mx[0]));
    tr[k].mx[1] = max(tr[k].mx[1],max(tr[tr[k].l].mx[1],tr[tr[k].r].mx[1]));
    tr[k].mi[0] = min(tr[k].mi[0],min(tr[tr[k].l].mi[0],tr[tr[k].r].mi[0]));
    tr[k].mi[1] = min(tr[k].mi[1],min(tr[tr[k].l].mi[1],tr[tr[k].r].mi[1]));
}

inline int dis(Point a,Point b){
    return abs(a[0]-b[0])+abs(a[1]-b[1]);
}

int calc(int k,Point x){
    int res =0 ;
    for(int i =0;i<2;i++){
        res+=max(0,tr[k].mi[i]-x[i]);
        res+=max(0,x[i]-tr[k].mx[i]);
    }
    return res;
}

void build(int& k,int l,int r,int d){
    dim = d;k = ++cnt;
    nth_element(p+l,p+mid,p+r+1);
    tr[k].t = p[mid];
    for(int i=0;i<2;i++)
        tr[k].mx[i] = tr[k].mi[i] = p[mid][i];
    if(l<mid) build(tr[k].l,l,mid-1,d^1);
    if(mid<r) build(tr[k].r,mid+1,r,d^1);
    pushup(k);
}

void insert(int& k,Point pt,int d){
    if(!k){
        k=++cnt;
        for(int i=0;i<2;i++){
            tr[k].mx[i] = tr[k].mi[i] = pt[i];
        }
        tr[k].t = pt;return;
    }
    dim = d;
    if(pt<tr[k].l) insert(tr[k].l,pt,d^1);
    else insert(tr[k].r,pt,d^1);
    pushup(k);
}

void query(int k,Point pt,int d){
    if(!k) return;
    ans = min(ans,dis(pt,tr[k].t));
    int lv = INF,rv =INF;
    if(tr[k].l) lv = calc(tr[k].l,pt);
    if(tr[k].r) rv = calc(tr[k].r,pt);
    if(lv<rv){
        if(lv<ans) query(tr[k].l,pt,d^1);
        if(rv<ans) query(tr[k].r,pt,d^1);
    }else{
        if(rv<ans) query(tr[k].r,pt,d^1);
        if(lv<ans) query(tr[k].l,pt,d^1);
    }
}


int main(){
    cin>>n>>m;
    for(int i =1;i<=n;i++){
        cin>>p[i][0]>>p[i][1];
    }
    build(root,1,n,0);
    for(int opt,x,y,i=1;i<=m;i++){
        cin>>opt>>x>>y;
        if(opt==1) insert(root,Point(x,y),0);
        else{
            ans = INF;
            query(root,Point(x,y),0);
            cout<<ans<<endl;
        }
    }
    return 0;
}