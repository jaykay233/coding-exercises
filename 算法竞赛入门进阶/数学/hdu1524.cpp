#include <bits/stdc++.h>
using namespace std;

const int maxn = 2005,INF=0x7fffffff;
int head[maxn],sg[maxn];
int cnt;

struct node{
    int u,v,next;
}Node[maxn*maxn];

void add(int u,int v){
    Node[cnt].u = u;
    Node[cnt].v = v;
    Node[cnt].next = head[u];
    head[u] = cnt++;
}

int mex(int u){
    if(sg[u]!=-1) return sg[u];
    bool vis[maxn];
    memset(vis,false,sizeof vis);
    for(int i=head[u];i!=-1;i=Node[i].next){
        node e = Node[i];
        sg[e.v] = mex(e.v);
        vis[sg[e.v]] = 1;
    }
    for(int i=0;;i++)
        if(!vis[i])
            return i;
    return 0;
}


int main(){
    int n;
    while(cin>>n){
        memset(sg,-1,sizeof sg);
        memset(head,-1,sizeof head);
        cnt = 0;
        int k;
        for(int i =0;i<n;i++){
            cin>>k;
            for(int j=0;j<k;j++){
                int v;
                cin>>v;
                add(i,v);
            }
        }

        int m, res= 0 ;
        while(cin>>m && m){
            int u;
            res = 0;
            for(int i=0;i<m;i++){
                cin>>u;
                res ^= mex(u);
            }
            if(res) cout<<"WIN"<<endl;
            else cout<<"LOSE"<<endl;
        }
    }

    return 0;
}