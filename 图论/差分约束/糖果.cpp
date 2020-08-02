#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N = 1e5+10;
const int K = 3e5+10;
int h[N],e[K],ne[K],w[K];
int x,a,b;
long long dist[N];
int idx =0 ;
int cnt[N];
bool st[N];
int q[N];

void add(int a,int b,int c){
    e[idx] = b;w[idx] = c;ne[idx] = h[a];h[a] = idx++;
}

bool spfa(){
    int hh = 0,tt = 1;
    memset(dist,-0x3f,sizeof dist);
    dist[0] = 0;
    st[0] = true;
    q[0] = 0;
    while(hh!=tt){
        int t = q[hh++];
        if(hh==N) hh = 0;
        st[t] = false;
        for(int i =h[t];i!=-1;i=ne[i]){
            int j = e[i];
            if(dist[j]< dist[t]+w[i]){
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if(cnt[j]>=n+1) return false;
                if(!st[j]){
                    q[tt++] = j;
                    if(tt==N) tt =0 ;
                    st[j] = true;
                }
            }
        }
    }
    return true;
}


int main(){
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof h);
    while(m--){
        cin>>x>>a>>b;
        if(x==1) add(a,b,0),add(b,a,0);
        else if(x==2) add(a,b,1);
        else if(x==3) add(b,a,0);
        else if(x==4) add(b,a,1);
        else add(a,b,0);
    }

    for(int i =1;i<=n;i++) add(0,i,1);
    if(!spfa()) puts("-1");
    else{
        long long res=0;
        for(int i=1;i<=n;i++) res+=dist[i];
        printf("%lld\n",res);
    }

    return 0;
}