#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N = 1e5+10;
vector<int> v;
int A[N];
struct node{
    int l,r,sum;
}nodes[N*20];
int root[N];
int cnt =0 ;

int getid(int x){
    return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}

void insert(int l,int r,int pre,int &now,int p)
{
    nodes[++cnt]=nodes[pre];
    now=cnt;
    nodes[now].sum++;
    if(l==r) return;
    int m = (l+r)>>1;       //>>1    =     /2
    if(p<=m) insert(l,m,nodes[pre].l,nodes[now].l,p);
    else insert(m+1,r,nodes[pre].r,nodes[now].r,p);
}
int query(int l,int r,int L,int R,int k)
{
    if(l==r) return l;
    int m = (l+r)>>1;
    int tmp = nodes[nodes[R].l].sum-nodes[nodes[L].l].sum;
    if(k<=tmp) return query(l,m,nodes[L].l,nodes[R].l,k);
    else return query(m+1,r,nodes[L].r,nodes[R].r,k-tmp);
}

int main(){
    cin>>n>>m;
    for(int i =1;i<=n;i++){
        cin>>A[i];
        v.push_back(A[i]);    
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    

    for(int i =1;i<=n;i++){
        insert(1,n,root[i-1],root[i],getid(A[i]));
    }

    for(int i =1;i<=m;i++){
        int l,r,k;
        cin>>l>>r>>k;
        // cout<<l<<" "<<r<<endl;
        cout<<v[query(1,n,root[l-1],root[r],k)-1]<<endl;
    }
}