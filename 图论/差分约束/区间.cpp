#include <bits/stdc++.h>
using namespace std;
int n;
const int N =50010,M = 150010;
int h[N],e[M],w[M],ne[M],idx;
int dist[N];
int q[N];
bool st[N];

void add(int a,int b,int c){
    e[idx] =b;w[idx] = c;ne[idx] = h[a];h[a] = idx++;
}

void spfa(){
    memset(dist,-0x3f,sizeof dist);
    dist[0] = 0;
    st[0] = true;
    q[0] = 0;
    int hh =0 ,tt = 1;
    while(hh!=tt){
        int t=q[hh++];
        if(hh==N) hh = 0;
        st[t] = false;
        for(int i =h[t];i!=-1;i=ne[i]){
            int j = e[i];
            if(dist[j]<dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                if(!st[j]){
                    q[tt++] = j;
                    if(tt==N) tt =0;
                    st[j] = true;
                }
            }
        }
    }
}

int main(){
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i =1;i<N;i++){
        add(i-1,i,0);
        add(i,i-1,-1);
    }
    for(int i =0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        a++,b++;
        add(a-1,b,c);
    }
    
    spfa();
    cout<<dist[50001]<<endl;

    return 0;
}