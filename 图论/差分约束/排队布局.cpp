#include <bits/stdc++.h>
using namespace std;
int n,m1,m2;
const int N = 1010,M = 30000,INF = 0x3f3f3f3f;
int h[N],e[M],w[M],ne[M];
int idx= 0 ;
bool st[N];
int q[N],cnt[N];
int dist[N];

void add(int a,int b,int c){
    e[idx] = b;w[idx] = c;ne[idx] = h[a];h[a] = idx++;
}

bool spfa(int k){
    memset(cnt,0,sizeof cnt);
    memset(dist,0x3f,sizeof dist);
    memset(st,false,sizeof st);
    int hh =0 ,tt = 0;
    for(int i=1;i<=k;i++){
        q[tt++] = i;
        st[i] = true;
        dist[i] = 0;
    }
    while(hh!=tt){
        int t = q[hh++];
        if(hh==N) hh = 0;
        st[t] = false;
        for(int i =h[t];i!=-1;i=ne[i]){
            int j = e[i];
            if(dist[j]>dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] +1;
                if(cnt[j]>=n) return true;
                if(!st[j]){
                    q[tt++] = j;
                    if(tt==N) tt =0;
                    st[j] = true;
                }
            }
        }
    }
    return false;
}



int main(){
    memset(h,-1,sizeof h);
    cin>>n>>m1>>m2;
    for(int i =0;i<m1;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(a>b) swap(a,b);
        add(a,b,c);
    }

    for(int i=0;i<m2;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(a>b) swap(a,b);
        add(b,a,-c);
    }

    if(spfa(n)) puts("-1");
    else{
        spfa(1);
        if(dist[n] == INF) puts("-2");
        else cout<<dist[n]<<endl;
    }

    return 0;
}