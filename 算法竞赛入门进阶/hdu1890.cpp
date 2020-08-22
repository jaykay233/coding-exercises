#include <bits/stdc++.h>
using namespace std;
const int maxn=100010;
int root;
int rev[maxn],pre[maxn],sz[maxn];
int tree[maxn][2];
struct node{
    int val,id;
    bool operator<(const node &A) const{
        if(val==A.val) return id<A.id;
        return val<A.val;
    }
}nodes[maxn];

void pushup(int x){
    sz[x] = sz[tree[x][0]] + sz[tree[x][1]] + 1;
}

void update_rev(int x){
    if(!x) return;
    swap(tree[x][0],tree[x][1]);
    rev[x]^=1;
}

void pushdown(int x){
    if(rev[x]){
        update_rev(tree[x][0]);
        update_rev(tree[x][1]);
        rev[x] = 0;
    }
}

void Rotate(int x,int c){
    int y = pre[x];
    pushdown(y);
    pushdown(x);
    tree[y][!c] = tree[x][c];
    pre[tree[x][c]] = y;
    if(pre[y])
        tree[pre[y]][tree[pre[y]][1]==y]=x;
    pre[x]=pre[y];
    tree[x][c] = y;
    pre[y]=x;
    pushup(y);
}

void splay(int x,int goal){
    pushdown(x);
    while(pre[x]!=goal){
        if(pre[pre[x]]==goal){
            pushdown(pre[x]);pushdown(x);
            Rotate(x,tree[pre[x]][0]==x);
        }else{
            pushdown(pre[pre[x]]);pushdown(pre[x]);pushdown(x);
            int y = pre[x];
            int c=(tree[pre[y]][0]==y);
            if(tree[y][c]==x){
                Rotate(x,!c);
                Rotate(x,c);
            }else{
                Rotate(y,c);
                Rotate(x,c);
            }
        }
    }
    pushup(x);
    if(goal==0) root=x;
}

int get_max(int x){
    pushdown(x);
    while(tree[x][1]){
        x=tree[x][1];
        pushdown(x);
    }
    return x;
}

void del_root(){
    if(tree[root][0]==0){
        root=tree[root][1];
        pre[root] = 0;
    }
    else{
        int m = get_max(tree[root][0]);
        splay(m,root);
        tree[m][1]=tree[root][1];
        pre[tree[root][1]]=m;
        root=m;
        pre[root]=0;
        pushup(root);
    }
}

void newnode(int &x,int fa,int val){
    x=val;
    pre[x]=fa;
    sz[x]=1;
    rev[x]=0;
    tree[x][0]=tree[x][1]=0;
}

void buildtree(int &x,int l,int r,int fa){
    if(l>r) return;
    int mid = l + r >> 1;
    newnode(x,fa,mid);
    buildtree(tree[x][0],l,mid-1,x);
    buildtree(tree[x][1],mid+1,r,x);
    pushup(x);
}

void init(int n){
    root=0;
    tree[root][0]=tree[root][1]=pre[root]=sz[root]=0;
    buildtree(root,1,n,0);
}

int main(){
    int n;
    while(~scanf("%d",&n) && n){
        init(n);
        for(int i=1;i<=n;i++){
            scanf("%d",&nodes[i].val);
            nodes[i].id=i;
        }
        sort(nodes+1,nodes+n+1);
        for(int i=1;i<n;i++){
            splay(nodes[i].id,0);
            update_rev(tree[root][0]);
            printf("%d ",i+sz[tree[root][0]]);
            del_root();
        }
        printf("%d\n",n);
    }
    return 0;
}