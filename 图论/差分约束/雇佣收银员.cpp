#include <bits/stdc++.h>
using namespace std;
const int N = 30;
const int M = 1010;
int r[25];
int n;
int nums[25];
int h[N],e[M],w[M],ne[M];
int idx;
int q[N],dist[N];
bool st[N];
int cnt[N];

void add(int a,int b,int c){
    e[idx] = b;w[idx] = c;ne[idx] = h[a];h[a] = idx++;
}

void build(int c){
    memset(h,-1,sizeof h);
    idx =0 ;
    add(0,24,c),add(24,0,-c);
    for(int i=1;i<=7;i++) add(i+16,i,r[i]-c);
    for(int i=8;i<=24;i++) add(i-8,i,r[i]);
    for(int i =1;i<=24;i++){
        add(i,i-1,-nums[i]);
        add(i-1,i,0);
    }
}


bool spfa(int s24){
    build(s24);
    memset(h,-1,sizeof h);
    memset(cnt,0,sizeof cnt);
    memset(st,0,sizeof st);
    int hh =0 ,tt = 1;
    dist[0] = 0;
    q[0] =0;
    st[0] = true;
    while(hh!=tt){
        int t = q[hh++];
        if(hh==N) hh =0 ;
        st[t] = false;
        for(int i =h[t];i!=-1;i=ne[i]){
            int j = e[i];
            if(dist[j]<dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if(cnt[j]>=25) return false;
                if(!st[j]){
                    q[tt++] = j;
                    if(tt == N) tt =0;
                    st[j] = true;

                }
            }
        }
    }
    return true;
}   


int main(){
    int t;
    cin>>t;
    for(int i =0;i<t;i++){
        for(int i =1;i<=24;i++) cin>>r[i];
        cin>>n;
        for(int i =0;i<n;i++){
            int x;
            cin>>x;
            nums[x+1]++;
        }
        bool success = false;
        int k;
        for(k =0;k<1000;k++){
            if(spfa(k)){
                cout<<i<<endl;
                success = true;
                break;
            }
        }
        if(success) cout<<i<<endl;
        else puts("No Solution");
    }

    return 0;
}