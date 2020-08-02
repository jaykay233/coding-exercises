#include <bits/stdc++.h>
using namespace std;
const int N = 210;
const int M = N * N/2;
int match[N];
int h[N],e[M],ne[M];
int idx;
int m,n;
bool used[N];

void add(int a,int b){
    e[idx] = b;ne[idx] =h[a];h[a] = idx++;
}

int dfs(int u){
    for(int i =h[u];i!=-1;i=ne[i]){
        int j = e[i];
        if(!used[j]){
            used[j] = true;
            if(!match[j] || dfs(match[j])){
                match[j] = u;
                return true;
            }
        }
    }
    return false;
}

int main(){
    scanf("%d%d",&m,&n);
    int a,b;
    memset(h,-1,sizeof h);
    while(scanf("%d%d",&a,&b) && (a!=-1 && b!=-1)){
        add(a,b);
    }

    int res =0;
    for(int i =1;i<=m;i++){
        memset(used,false,sizeof used);
        if(dfs(i)) res++;
    }

    bool ok = false;
    vector<pair<int,int>> p;
    for(int i =m+1;i<=n;i++){
        if(match[i]){
            ok = true;
            p.push_back({match[i],i});
        }
    }
    if(p.empty()){
        cout<<"No Solution!"<<endl;
    }else{
        cout<<p.size()<<endl;
        for(auto t:p){
            cout<<t.first<<" "<<t.second<<endl;
        }
    }

    

    return 0;
}