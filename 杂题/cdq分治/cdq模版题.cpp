//这是二维的cdq分治
#include <bits/stdc++.h>
using namespace std;
int n,k;
typedef long long ll;
const int maxn = 500010;
const int maxq = maxn<<2;
struct Query{
    int type,idx;
    ll val;
    bool operator<(const Query& rhs) const{
        return idx==rhs.idx?type<rhs.type:idx<rhs.idx;
    }
}query[maxq];
int qidx =0 ;
int ans[maxn];
Query temp[maxq];

void cdq(int l,int r){
    if(r-l<=1) return;
    int mid = (l + r)>>1;
    cdq(l,mid);cdq(mid,r);
    int p = l,q = mid;
    ll sum = 0;
    int cnt =0 ;
    while(p<mid && q<r){
        if(query[p]<query[q]){
            if(!query[p].type) sum+=query[p].val;
            temp[cnt++] = query[p++];
        }else{
            if(query[q].type==1) ans[query[q].val]-=sum;
            else if(query[q].type==2) ans[query[q].val]+=sum;
            temp[cnt++] = query[q++];
        }
    }
    while(p<mid) temp[cnt++] = query[p++];
    while(q<r){
        if(query[q].type==1) ans[query[q].val] -=sum;
        else if(query[q].type==2) ans[query[q].val]+=sum;
        temp[cnt++] = query[q++];
    }
    for(int i=l;i<r;i++) query[i] = temp[i-l];
}

int main(){
    cin>>n>>k;
    int tot = 0;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        query[++tot].type = 0;
        query[tot].idx = i;
        query[tot].val = a;
    }

    for(int i =0;i<k;i++){
        int type,l,r;
        cin>>type>>l>>r;
        if(type==1){
            query[++tot].type = 0;
            query[tot].idx = l;
            query[tot].val = r;
        }else{
            query[++tot].type = 1;
            query[tot].idx = l-1;
            query[tot].val = ++qidx;
            query[++tot].type = 2;
            query[tot].idx = r;
            query[tot].val = qidx;
        }        
    }

    cdq(1,tot+1);

    for(int i =1;i<=qidx;i++) cout<<ans[i]<<endl;

    return 0;
}