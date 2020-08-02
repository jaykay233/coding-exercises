//第k度生成树
#include <bits/stdc++.h>
using namespace std;
unordered_map<string,int> m;
int k =0;
int n;
int s;
const int N=25;
const int M = N*N;
int p[N];
int h[N],e[M],ne[M],we[M];
int idx;
bool vis[N];
bool edge_vis[M];
int dist[N];
bool used[N][N];

void add(int u,int v,int w){
    e[idx] = v;we[idx] = w;ne[idx] = h[u];h[u] = idx++;
}


int mapping(string s){
    if(m.count(s)) return m[s];
    return m[s] = k++;
}

struct edge{
    int from,to,w;
    bool operator<(const edge& a) const{
        return w<a.w;
    }
};

vector<edge> no_root_edge;
vector<edge> root_edge;

int find(int a){
    if(p[a]==a) return a;
    return p[a] = find(p[a]);   
}

void dfs(int u,int fa,int v,int d[]){
    d[u] = v;
    for(int i =h[u];i!=-1;i=ne[i]){
        int j = e[i];
        if(j==fa ) continue;
        if(used[u][j] || used[j][u]) continue;
        dfs(j,u,max(v,we[i]),d);
    }
    return;
}


int main(){
    cin>>n;
    memset(h,-1,sizeof h);
    mapping("Park");
    string from,to;int w;
    for(int i =0;i<n;i++){
        cin>>from>>to>>w;
        if(mapping(from)== mapping("Park") || mapping(to)==mapping("Park")) root_edge.push_back({mapping(from),mapping(to),w});
        else no_root_edge.push_back({mapping(from),mapping(to),w});
    }
    cin>>s;
    sort(root_edge.begin(),root_edge.end());
    sort(no_root_edge.begin(),no_root_edge.end());
    for(int i =0;i<k;i++) p[i] = i;

    int res =0 ;
    for(int i =0;i<no_root_edge.size();i++){
        edge e =no_root_edge[i];
        int from = e.from,to = e.to,w = e.w;
        int ff = find(from);
        int ft = find(to);
        if(ff!=ft){
            p[ff] = ft;
            add(from,to,w);
            add(to,from,w);
            res += w;
        }
    }

    memset(vis,false,sizeof vis);
    int cnt = 0;

    for(int i =0;i<root_edge.size();i++){
        int from = root_edge[i].from;
        int to = root_edge[i].to;
        int w = root_edge[i].w;
        if(to == mapping("Park")) swap(from,to);
        int f_to = find(to);
        if(vis[f_to] || edge_vis[i]) continue;
        vis[f_to] = true;
        edge_vis[i] = true;
        add(mapping("Park"),to,w);
        add(to,mapping("Park"),w);
        res+=w;
        cnt++;
    }


    for(;cnt<s;cnt++){
        int minval = 0;
        int idx = -1;
        int w_temp = 0;
        int t_idx = -1;
        for(int i =0;i<root_edge.size();i++){
            if(edge_vis[i]) continue;
            dfs(0,-1,0,dist);
            int from = root_edge[i].from;
            int to = root_edge[i].to;
            if(to==mapping("Park")) swap(from,to);
            int w = root_edge[i].w;
            if(w - dist[to]<minval){
                minval = w-dist[to];
                idx = to;
                w_temp = w;
                t_idx = i;
            }
        }
        if(idx==-1) break;
        for(int it = h[idx];it!=-1;it=ne[it]){
            int j = e[it];
            if(we[it]==dist[idx]) {
                used[j][idx] = true;
                used[idx][j] = true;
                break;
            }
        }
        add(mapping("Park"),idx,w_temp);
        add(idx,mapping("Park"),w_temp);
        edge_vis[t_idx] = true;
        res += w_temp - dist[idx];
    }

    printf("Total miles driven: %d\n",res);
    cout<<res<<endl;
    
    return 0;
}