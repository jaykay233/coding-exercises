#include <bits/stdc++.h>
using namespace std;
map<int,bool> vis;
queue<pair<int,int>> q;
vector<int> v;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        vis[x] = 1;
        q.push({1,x-1});q.push({1,x+1});        
    }

    long long ans = 0;
    vector<int> v;
    while(!q.empty() && m>0){
        auto t = q.front();q.pop();
        if(!vis[t.second]){
            ans+=t.first; m--;
            v.push_back(t.second);
            vis[t.second] = 1;
            q.push({t.first+1,t.second-1});
            q.push({t.first+1,t.second+1});
        }
    }

    printf("%lld\n",ans);
    for(int t:v){
        cout<<t<<" ";
    }
    cout<<endl;
    return 0;
}