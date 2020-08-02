#include <bits/stdc++.h>
using namespace std;
int t;
int n;
const int N = 1010;
const int M = N*N;
int e[M],ne[M],h[N],idx;
bool st[N];
vector<int> cirs;
stack<int> path;

void add(int a,int b){
    e[idx] = b;ne[idx] = h[a];h[a] = idx++;
}

bool dfs(int u,int p){
    st[u] = true;
    path.push(u);
    for(int i =h[u];i!=-1;i=ne[i]){
        int j = e[i];
        if(j!=p){
            if(st[j]){
                while(path.top()!=j){
                    cirs.push_back(path.top());
                    path.pop();
                }
                cirs.push_back(j);
                return true;
            }
        }
        if(dfs(j,u)) return true;
    }

    path.pop();
    return false;
}

void dfs_depth(int u,int depth){
    st[u] = true;
    d[u] = depth;
    for(int i =h[u];i!=-1;i=ne[i]){
        int j = e[i];
        if(!st[j])
            dfs(j,depth+1);
    }
}

int main(){
    cin>>t;
    for(int i =1;i<=t;i++){
        memset(h,-1,sizeof h);
        memset(st,false,sizeof st);
        cin>>n;
        for(int i=1;i<=n;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            add(a,b);
            add(b,a);
        }

        dfs(1,-1);
        memset(st,false,sizeof st);
        for(auto c:cirs) st[c] = true;
        for(auto c:cirs) dfs_depth(c,0);

        printf("Case #%d:", i);
        for(int i=1;i<=n;i++) printf("%d\n",d[i]);
        puts("");
    }

    return 0;
}