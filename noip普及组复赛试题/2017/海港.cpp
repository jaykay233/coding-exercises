#include <bits/stdc++.h>
using namespace std;

struct p{
    int pt,pn;
};

queue<p> ship;
int n,vis[100005],sum;

int main(){
    scanf("%d",&n);
    while(n--){
        int t,m,n_;
        scanf("%d%d",&t,&m);
        for(int i=1;i<=m;i++){
            scanf("%d",&n_);
            p x;
            x.pt = t;
            x.pn = n_;
            ship.push(x);
            vis[n_] ++;
            if(vis[n_]==1) sum++;
        }
        while(1){
            int a,b;
            a = ship.front().pt;
            b = ship.front().pn;
            if(t-a<86400) break;
            vis[b] --;
            if(vis[b]==0) sum--;
            ship.pop();
        }
        printf("%d\n",sum);
    }
    return 0;
}