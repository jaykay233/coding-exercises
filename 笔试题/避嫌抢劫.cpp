#include <bits/stdc++.h>
using namespace std;
int n,d;
const int N = 2e5+10;
vector<pair<int,int>> dist;
int l[N];
int main(){
    cin>>n>>d;
    for(int i =1;i<=n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        dist.push_back({a,b});
    }
    int maxnum = 0;
    l[0] = dist[0].second;
    for(int i =1;i<n;i++){
        l[i] = max(l[i-1],dist[i].second);
        auto it = upper_bound(dist.begin(),dist.end(),make_pair(i-d,0));
        if(it!=dist.begin()){
            it --;
            int t = it-dist.begin();
            maxnum = max(maxnum,dist[i].second + l[t]);
        }
    }

    cout<<maxnum<<endl;

    return 0;
}