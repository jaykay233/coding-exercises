#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,int> pii;
const int maxn = 100010;
const int maxm = 200010;
int v[maxm],Next[maxm],w[maxm];
int first[maxn],pre[maxn],res[maxn],e;
LL d[maxn];
 
void init(){
    e = 0;
    memset(first,-1,sizeof(first));
}
 
void add_edge(int a,int b,int c){
    v[e] = b;Next[e] = first[a];w[e] = c;first[a] = e++;
}
 
void dijkstra(int src){
    priority_queue <pii,vector<pii>,greater<pii> > q;
    memset(d,-1,sizeof(d));
    d[src] = 0;
    q.push(make_pair(0,src));
    while(!q.empty()){
        while(!q.empty() && q.top().first > d[q.top().second])  q.pop();
        if(q.empty())   break;
        int u = q.top().second;
        q.pop();
        for(int i = first[u];i != -1;i = Next[i]){
            if(d[v[i]] > d[u]+w[i] || d[v[i]] == -1){
                d[v[i]] = d[u]+w[i];
                q.push(make_pair(d[v[i]],v[i]));
                pre[v[i]] = u;
            }
        }
    }
}
 
int main(){
    init();
    int n,m,a,b,c;
    scanf("%d%d",&n,&m);
    for(int i = 0;i < m;i++){
        scanf("%d%d%d",&a,&b,&c);
        add_edge(a,b,c);
        add_edge(b,a,c);
    }
    dijkstra(1);
    int now = n,cnt = 0;
    if(d[n] == -1){
        printf("-1");
        return 0;
    }
    while(now != 1){
        res[cnt++] = now;
        now = pre[now];
    }
    res[cnt++] = 1;
    for(int i = cnt-1;i >= 0;i--)  printf("%d ",res[i]);
    return 0;
}