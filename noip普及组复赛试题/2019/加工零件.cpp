#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5+10;
queue<PII> q;
int e[N*4],h[N*2],ne[N*4];
int dist[N*2][2];
int idx =0 ;

void add(int a,int b){
    e[idx] = b;ne[idx]=h[a];h[a]=idx++;
}

void bfs(){
    memset(dist,0x3f,sizeof dist);
    dist[1][0] = 0;
    q.push({1,0});
    while(!q.empty()){
        auto t = q.front();q.pop();
        int node = t.first,type = t.second, distance = dist[node][type];
        for(int i =h[node];i!=-1;i=ne[i]){
            int j = e[i];
            if(dist[j][type^1] > distance+1){
                dist[j][type^1] = distance+1;
                q.push({j,type^1});
            }
        }
    }
}

int n,m,Q;

int main(){
    memset(h,-1,sizeof h);
    scanf("%d%d%d",&n,&m,&Q);
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
        add(b,a);
    }
    bfs();
    for(int i =1;i<=Q;i++){
        int a,L;
        scanf("%d%d",&a,&L);
        if(h[a]==-1) puts("No");
        else if(L>=dist[a][L&1]) puts("Yes");
        else puts("No");
    }
    
    
    return 0;
}