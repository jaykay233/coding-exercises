#include <bits/stdc++.h>
using namespace std;
int n,m,s,t;
const int N = 10010, M = 2e5+10;
int h[N],e[M],ne[M],w[M];
int idx= 0 ;
int pre[N],vis[N];
int num[N];

void add(int a,int b,int c){
    e[idx] = b;w[idx] =c;ne[idx] =h[a];h[a]=idx++;
}

bool bfs(int s,int t){
    memset(pre,0,sizeof pre);
    memset(vis,0,sizeof vis);
    queue<int> q;
    q.push(s);vis[s] =1 ;
    while(!q.empty()){
        int u = q.front();q.pop();
        for(int i =h[u];i!=-1;i=ne[i]){
            int v = e[i];
            if(!vis[v] && w[i]){
                pre[v] = u;num[v] = i;q.push(v);vis[v] = 1;
                if(v==t) return 1;
            }
        }
    }
    return 0;
}



int EK(int s,int t){
    int ans =0 ;
    while(bfs(s,t)){
        int mn = INT_MAX;
        for(int i =t;i!=s;i=pre[i]) mn = min(mn,w[num[i]]);
        for(int i =t;i!=s;i=pre[i]){
            int x = num[i];
            w[x] -= mn,w[x^1] += mn;
        }
        ans+=mn;
    }
    return ans;
}


int main(){
    memset(h,-1,sizeof h);
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);add(b,a,0);
    }   
    printf("%d\n",EK(s,t));

    return 0;
}