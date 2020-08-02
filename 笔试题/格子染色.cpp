#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
typedef long long LL;

struct Segment{
    int k;
    int l,r;
    bool operator<(const Segment& w) const{
        if(k!=w.k) return k<w.k;
        if(l!=w.l) return l<w.l;
        return r<w.r;
    }
};


LL merge(vector<Segment>& q){
    sort(q.begin(),q.end());
    vector<Segment> w;
    LL res= 0 ;
    for(int i =0;i<q.size();){
        int j = i;
        while(j<q.size() && q[j].k == q[i].k) j++;
        int l = -2e9, r = l -1;
        for(int k=i;k<j;k++)
            if(r <q[k].l){
                res+= r - l + 1;
                if(l!=-2e9) w.push_back({q[i].k,l,r});
                l = q[k].l , r = q[k].r;
            }else{
                r = max(r,q[k].r);
            }
        if(l!=-2e9) w.push_back({q[i].k,l,r});
        res += r - l + 1;
        i = j;
    }
    q = w;
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<Segment> rows,cols;
    while(n--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        if(x1==x2) cols.push_back({x1,min(y1,y2),max(y1,y2)});
        else rows.push_back({y1,min(x1,x2),max(x1,x2)});
    }

    LL res = merge(rows) + merge(cols);

    for(auto r:rows){
        for(auto c:cols){
            if(r.k>=c.l && r.k<=c.r && c.k>=r.l && c.k<=r.r)
                res--;
        }
    }

    cout<<res<<endl;

    return 0;
}