#include <bits/stdc++.h>
using namespace std;
const int N = 510, M =5210;
int n,m1,m2;
int h[N],w[M],ne[M],e[M];
int dist[N];
int q[N],cnt[N];
bool st[N];
int idx =0;

void add(int a,int b,int c){
    e[idx] = b;w[idx] = c;ne[idx] = h[a];h[a] = idx++;
}

bool spfa(){
    int hh = 0, tt = 0;
    memset(st,false,sizeof st);
    memset(cnt,0,sizeof cnt);
    memset(dist,0,sizeof dist);
    for(int i =1;i<=n;i++){
        q[tt++] = i;
        st[i] = true;
    }

    while(hh!=tt){
        int t = q[hh++];
        if(hh == N) hh = 0;
        st[t] = false;
        for(int i = h[t];i!=-1;i=ne[i]){
            int j = e[i];
            if(dist[j] > dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >= n) return true;
                if(!st[j]){
                    q[tt++] = j;
                    if(tt == N) tt = 0;
                    st[j] = true;
                }
            }
        }
    }
    return false;
}

int main(){
    int f;
    cin>>f;
    for(int i =0;i<f;i++){
        cin>>n>>m1>>m2;
        memset(h,-1,sizeof h);
        idx =0 ;
        for(int i = 0;i<m1;i++){
            int s,e,t;
            cin>>s>>e>>t;
            add(s,e,t);
            add(e,s,t);
        }
        for(int i =0;i<m2;i++){
            int s,e,t;
            cin>>s>>e>>t;
            add(s,e,-t);
        }
        if(spfa()) puts("YES");
        else puts("NO");

    }
    return 0;
}