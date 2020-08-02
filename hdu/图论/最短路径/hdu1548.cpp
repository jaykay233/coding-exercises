#include <bits/stdc++.h>
using namespace std;
const int N = 210;
int k[N];
int n,a,b;
const int M = N * N;
int h[N],e[M],ne[M];
int idx;
int dist[N];
int q[N];
bool st[N];
int w[M];

void add(int a,int b,int c){
    e[idx] = b;w[idx] = c;ne[idx] = h[a];h[a] = idx++;
}

void spfa(int S)
{
    memset(dist, 0x3f, sizeof dist);
    dist[S] = 0;

    int hh = 0, tt = 1;
    q[0] = S, st[S] = true;

    while (hh != tt)
    {
        int t = q[hh ++ ];
        if (hh == N) hh = 0;
        st[t] = false;

        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if (!st[j])
                {
                    q[tt ++ ] = j;
                    if (tt == N) tt = 0;
                    st[j] = true;
                }
            }
        }
    }
}


int main(){
    while(~scanf("%d",&n)){
        if(n==0) break;
        scanf("%d%d",&a,&b);
        memset(h,-1,sizeof h);
        idx =0 ;
        for(int i =1;i<=n;i++) scanf("%d",&k[i]);
        for(int i =1;i<=n;i++){
            int s = k[i];
            if(i-s>=1) add(i,i-s,1);
            if(i+s<=n) add(i,i+s,1);
        }
        spfa(a);
        if(dist[b] > 0x3f3f3f3f/2)
            cout<<"-1"<<endl;
        else
            cout<<dist[b]<<endl;
    }
    return 0;
}