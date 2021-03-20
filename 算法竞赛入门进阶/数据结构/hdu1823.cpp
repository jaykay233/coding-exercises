#include <bits/stdc++.h>
using namespace std;
const int Maxn= 101;
struct Tree{
    int l,r;
    int mh;
};

struct MTree{
    int l,r;
    Tree tree[Maxn*4*10];
}mt[Maxn<<2];

void BTree(int mk,int k,int l,int r){
    mt[mk].tree[k].l = l;
    mt[mk].tree[k].r = r;
    if(l==r){
        mt[mk].tree[k].mh = -1;
        return;
    }
    int mid = l + r >> 1;
    BTree(mk,k<<1,l,mid);
    BTree(mk,k<<1|1,mid+1,r);
    mt[mk].tree[k].mh = max(mt[mk].tree[k<<1].mh, mt[mk].tree[k<<1|1].mh);
}

void BMTree(int k,int l,int r){
    mt[k].l = l;
    mt[k].r = r;
    BTree(k,1,0,1000);
    if(l==r)
        return;
    int mid = l + r >> 1;
    BMTree(k<<1,l,mid);
    BMTree(k<<1|1,mid+1,r);
}

void addP_tree(int mk,int k,int A,int L){
    if(mt[mk].tree[k].l == mt[mk].tree[k].r && mt[mk].tree[k].l == A){
        mt[mk].tree[k].mh = max(mt[mk].tree[k].mh,L);
        return;
    }
    int mid = (mt[mk].tree[k].l + mt[mk].tree[k].r) >> 1;
    if(mid>=A)  
        addP_tree(mk,k<<1,A,L);
    else
        addP_tree(mk,k<<1|1,A,L);
    mt[mk].tree[k].mh = max(mt[mk].tree[k<<1].mh,mt[mk].tree[k<<1|1].mh);
}

void addP_mt(int k,int H,int A,int L){
    if(mt[k].l == mt[k].r && mt[k].l == H){
        addP_tree(k,1,A,L);
        return;
    }
    int mid = (mt[k].l + mt[k].r) >> 1;
    if(mid>=H)
        addP_mt(k<<1,H,A,L);
    else
        addP_mt(k<<1|1,H,A,L);
    addP_tree(k,1,A,L);
}

int ans;
void query_tree(int mk,int k,int al,int ar){
    if(mt[mk].tree[k].l>=al && ar>=mt[mk].tree[k].r){
        ans = max(ans,mt[mk].tree[k].mh);
        return;
    }
    int mid = (mt[mk].tree[k].l + mt[mk].tree[l].r) >> 1;
    if(ar<=mid)
        query_tree(mk,k<<1,al,ar);
    else if(al>mid)
        query_tree(mk,k<<1|1,al,ar);
    else{
        query_tree(mk,k<<1,al,mid);
        query_tree(mk,k<<1|1,mid+1,ar);
    }
}

void query_mt(int k,int hl,int hr,int al,int ar){
    if(mt[k].l>=hl && mt[k].r<=hr){
        query_tree(k,1,al,ar);
        return;
    }
    int mid = (mt[k].l + mt[k].r) >> 1;
    if(hr<=mid)
        query_mt(k<<1,hl,hr,al,ar);
    else if(hl>mid)
        query_mt(k<<1|1,hl,hr,al,ar);
    else{
        query_mt(k<<1,hl,mid,al,ar);
        query_mt(k<<1|1,mid+1,hr,al,ar);
    }
}


int main(){
    int n;
    char s[5];
    int H,H1,H2;
    double A,L,A1,A2;
    while(~scanf("%d",&n)&&n){
        memset(mt,0,sizeof mt);
        BMTree(1,100,200);
        while(n--){
            scanf("%s",s);
            if(s[0]=='I'){
                scanf("%d%lf%lf",&H,&A,&L);
                addP_mt(1,H,(int)(A*10),(int)(L*10));
            }
            else if(s[0]=='Q'){
                scanf("%d%d%lf%lf",&H1,&H2,&A1,&A2);
                ans =-1;
                query_mt(1,min(H1,H2),max(H1,H2),min((int)(A1*10),(int)(A2*10)), max((int)(A1*10),(int)(A2*10)));
                if(ans!=-1)
                    printf("%.11f\n",(double)(ans*1.0/10));
                else
                    printf("-1\n");
            }
        }
    }

    return 0;
}