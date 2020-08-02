#include <iostream>
#include <utility>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <climits>
using namespace std;
const int N = 1e6+10;
struct seg{
    int l,r,cnt;
    bool is_merge;
}segs[N<<2];
vector<pair<int,int>> quries;

struct Debug{
    unordered_map<int,vector<seg>> m;
}debug;

void print(int level,int node){
    debug.m[level].push_back(segs[node]);
    if(segs[node].l == segs[node].r) {
        cout<<segs[node].cnt<<endl;
        return;
    }
    print(level+1,node<<1);
    print(level+1,node<<1|1);
    return;
}

void show(){
    print(1,1);
    for(auto p:debug.m){
        vector<seg> nodes = p.second;
        printf("level %d:\n",p.first);
        for(auto node:nodes){
            cout<<"cnt: "<<node.cnt<<" is_merge: "<<node.is_merge<<endl;
        }
    }
    debug.m.clear();
}

void log(int level,int l,int r,int node){
    if(level==0){
        cout<<"filling"<<" ";
    }else{
        cout<<"querying"<<" ";
    }
    cout<<"interval :"<<l<<" "<<r<<" node:"<<segs[node].l<<" "<<segs[node].r<<endl;
}




void build(int l,int r,int node){
    segs[node].l = l;
    segs[node].r = r;
    segs[node].cnt = 0;
    segs[node].is_merge = false;
    if(segs[node].l == segs[node].r) {
        segs[node].is_merge = true;
        return;
    }
    int mid = (l+r)>>1;
    build(l,mid,node<<1);
    build(mid+1,r,node<<1|1);
    return;
}


void pushup(int node){
    if(segs[node<<1].is_merge && segs[node<<1 | 1].is_merge){
        if(segs[node<<1].cnt== segs[node<<1|1].cnt){
            segs[node].is_merge = true;
            segs[node].cnt = segs[node<<1].cnt;
        }
        else segs[node].is_merge = false;
    }
    return;
}


void fill(int l,int r,int node,int a){
    if(l>segs[node].r || r<segs[node].l) return;
    // log(0,l,r,node);

    if(segs[node].l == segs[node].r){
        segs[node].cnt += a;
    }else{
        fill(l,r,node<<1,a);
        fill(l,r,node<<1|1,a);
    }
    pushup(node);
    return;
}

int query(int l,int r,int node){
    if(segs[node].l>r || segs[node].r<l) return 0;
    // log(1,l,r,node);

    if(l<=segs[node].l && segs[node].r<=r ){
        if(segs[node].is_merge){
            if(segs[node].cnt == 1)
                return segs[node].r - segs[node].l+1;
            else
                return 0;
        }
    }
    int mid = (segs[node].l + segs[node].r)>>1;
    int res = 0;
    if(l<=mid) res+=query(l,r,node<<1);
    if(r>mid) res+=query(l,r,node<<1|1);
    return res;
    
    return 0;
}




int main(){
    int T;
    cin>>T;
    int n,q;
    
    for(int t =1;t<=T;t++){
        cin>>n>>q;
        quries.clear();
        memset(segs,0,sizeof segs);
        build(1,n,1);
        for(int i =1;i<=q;i++){
            int a,b;
            cin>>a>>b;
            // cout<<a<<" "<<b<<endl;
            quries.push_back({a,b});
            fill(a,b,1,1);
        }
        // show();

        vector<bool> valid(q,true);
        int ans =INT_MAX;

        for(int j =0;j<q;j++){
            int idx = -1;
            int max_num = 0;
            for(int i =0;i<q;i++){
                if(valid[i]) {
                    idx = i;
                    break;
                }
            }

            for(int i =0;i<q;i++){
                if(valid[i]){
                    int res = query(quries[i].first,quries[i].second,1);
                    // cout<<"res is "<<res<<endl;
                    if(res>=max_num){
                        max_num = res;
                        idx = i;
                    }
                }
            }
            // cout<<max_num<<endl;
            // cout<<idx<<endl;
            valid[idx] = false;
            ans = min(ans,max_num);
            fill(quries[idx].first,quries[idx].second,1,-1);
        }

        printf("Case #%d: %d\n",t,ans);

    }

    // show();
    




    return 0;
}