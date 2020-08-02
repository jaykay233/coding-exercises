#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
const int maxn = 1e5+5;
const double alpha = 0.75;
struct node{
    int l,r,val;
    int size,fact;
    bool exist;
}tzy[maxn];
int cnt,root;

void newnode(int& now,int val){
    now=++cnt;
    tzy[now].val = val;
    tzy[now].size = tzy[now].fact = 1;
    tzy[now].exist = true;
}

bool imbalence(int now)
{
    if(std::max(tzy[tzy[now].l].size,tzy[tzy[now].r].size)>tzy[now].size*alpha
       ||tzy[now].size-tzy[now].fact>tzy[now].size*0.3)
        return true;
    return false;
}

#include <vector>
std::vector<int> v;

void ldr(int now){
    if(!now) return;
    ldr(tzy[now].l);
    if(tzy[now].exist)
        v.push_back(now);
    ldr(tzy[now].r);
}

void lift(int l,int r,int& now){
    if(l==r){
        now = v[l];
        tzy[now].l = tzy[now].r = 0;
        tzy[now].size = tzy[now].fact = 1;
        return;
    }
    int m = (l + r)>>1;
    while(m>0 && tzy[v[m]].val == tzy[v[m-1]].val) m--;
    now = v[m];
    if(l<m) lift(l,m-1,tzy[now].l);
    else tzy[now].l =0 ;
    lift(m+1,r,tzy[now].r);
    tzy[now].size = tzy[tzy[now].l].size+tzy[tzy[now].r].size+1;
    tzy[now].fact = tzy[tzy[now].l].fact + tzy[tzy[now].r].fact +1;
}

void rebuild(int& now){
    v.clear();
    ldr(now);
    if(v.empty()){
        now = 0;
        return;
    }
    lift(0,v.size()-1,now);
}

void update(int now,int end){
    if(!now) return;
    if(tzy[end].val<tzy[now].val)
        update(tzy[now].l,end);
    else update(tzy[now].r,end);
    tzy[now].size = tzy[tzy[now].l].size + tzy[tzy[now].r].size + 1;
}


void check(int& now,int end){
    if(now==end) return;
    if(imbalence(now)){
        rebuild(now);
        update(root,now);
        return;
    }
    if(tzy[end].val<tzy[now].val)
        check(tzy[now].l,end);
    else check(tzy[now].r,end);
}

void insert(int& now,int x){
    if(!now){
        newnode(now,x);
        check(root,now);
        return;
    }
    tzy[now].size++;
    tzy[now].fact++;
    if(x<tzy[now].val){
        insert(tzy[now].l,x);
    }
    else insert(tzy[now].r,x);
}

void del(int& now,int x){
    if(tzy[now].exist && tzy[now].val == x){
        tzy[now].exist = false;
        tzy[now].fact--;
        check(root,now);
        return;
    }
    tzy[now].fact--;
    if(x<tzy[now].val) del(tzy[now].l,x);
    else del(tzy[now].r,x);
}

int getrank(int val){
    int now = root,rank = 1;
    while(now){
        if(val<=tzy[now].val)
            now = tzy[now].l;
        else{
            rank +=tzy[now].exist + tzy[tzy[now].l].fact;
            now = tzy[now].r;
        }
    }
    return rank;
}

int getnum(int rank){
    int now =root;
    while(now){
        if(tzy[now].exist && tzy[tzy[now].l].fact + tzy[now].exist == rank)
            break;
        else if(tzy[tzy[now].l].fact>=rank)
            now = tzy[now].l;
        else{
            rank-=tzy[tzy[now].l].fact + tzy[now].exist;
            now = tzy[now].r;
        }
    }
    return tzy[now].val;
}




int main(){
    cin>>n;
    int opt,x;
    for(int i = 1;i<=n;i++){
        cin>>opt>>x;
        if(opt==1){
            insert(root,x);
        }
        if(opt==2){
            del(root,x);
        }
        if(opt==3){
            cout<<getrank(x)<<endl;
        }
        if(opt==4){
            cout<<getnum(x)<<endl;
        }
        if(opt==5){
            cout<<getnum(getrank(x)-1)<<endl;
        }
        if(opt==6){
            cout<<getnum(getrank(x+1))<<endl;
        }
    }   

    return 0;
}