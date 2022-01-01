#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int mod = 1e9+7;
const int msz = 100100;
typedef long long ll;
const ll INF = 0x3f3f3f3f;

struct Point {
    ll x,y;
    int id;
};

ll dist(Point a,Point b){
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

Point p[msz];
Point tmpt[msz];

bool cmpxy(Point a,Point b){
    if(a.x!=b.x) return a.x < b.x;
    return a.y < b.y;
}

bool cmpy(Point a,Point b){
    return a.y < b.y;
}

ll d;
int pt[2];

void closest_pair(int left, int right, int opt){
    if( left == right ) return;
    ll tmp;
    if (left + 1 == right){
        if(p[left].id!=opt && p[right].id !=opt){
            tmp = dist(p[left],p[right]);
            if(d>tmp){
                d = tmp;
                if(opt==-1)
                {
                    pt[0] = p[left].id;
                    pt[1] = p[right].id;
                }
            }
        }
        return;
    }
    int mid = (left + right) >> 1;
    closest_pair(left, mid ,opt);
    closest_pair(mid+1, right, opt);
    int k = 0;
    for(int i = left; i <= right;i++){
        if(p[i].id !=opt && abs(p[mid].x - p[i].x) <= d)
            tmpt[k++] = p[i];
    }
    sort(tmpt, tmpt+k, cmpy);
    for(int i =0;i<k;i++){
        for(int j =i+1;j<k && tmpt[j].y - tmpt[i].y < d; j++)
        {
            tmp = dist(tmpt[i], tmpt[j]);
            if( d > tmp){
                if(opt == -1){
                    pt[0] = tmpt[i].id;
                    pt[1] = tmpt[j].id;
                }
                d = tmp;
            }
        }
    }
}

int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lld%lld",&p[i].x, &p[i].y);
            p[i].id = i;
        }
        sort(p,p+n,cmpxy);
        d = INF;
        closest_pair(0,n-1,-1);
        ll ans = d * (n-2);
        d = INF;
        closest_pair(0,n-1,pt[0]);
        ans += d;
        closest_pair(0,n-1,pt[1]);
        ans += d;
        printf("%lld\n",ans);
    }
    return 0;
}