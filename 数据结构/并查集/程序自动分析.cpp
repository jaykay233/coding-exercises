#include <bits/stdc++.h>
using namespace std;
int t,n;
const int N = 1000010;
int p[2*N];
unordered_map<int,int> h;

int find(int a){
    if(p[a]==a) return a;
    return p[a] = find(p[a]);
}

int m(int x){
    if(h.count(x)) return h[x];
    return h[x] = h.size()+1;
}


int main(){
    scanf("%d",&t);
    for(int i =1;i<=t;i++){
        scanf("%d",&n);
        bool ok = true;
        vector<pair<int,int>> pp;
        for(int i =1;i<=2*N-1;i++) p[i] = i;
        for(int i =1;i<=n;i++){
            int x,y,e;
            scanf("%d%d%d",&x,&y,&e);
            x = m(x);
            y = m(y);
            if(e==1){
                if(find(x)!=find(y)){
                    p[find(x)] = find(y);
                }
            }
            else if(e==0){
                pp.push_back({x,y});
            }
        }
        for(auto item:pp){
            int x = item.first, y = item.second;
            if(find(x)==find(y)){
                ok = false;
                break;
            }
        }
        
        if(ok) puts("YES");
        else puts("NO");
    }

    return 0;
}