#include <bits/stdc++.h>
using namespace std;
int m;
const int M = 1e5+10;
const int N = 700;
int h[N],e[M],ne[M],w[M];
int idx;
bool st[N];
double dist[N];
int cnt[N];
int q[N];

void add(int a,int b,int c){
    e[idx] = b;w[idx] = c;ne[idx] = h[a];h[a] = idx++;
}

bool check(double mid){
    memset(cnt,0,sizeof cnt);
    memset(dist,0,sizeof dist);
    memset(st,false,sizeof st);
    int hh = 0, tt = 0;
    for(int i=0;i<676;i++){
        q[tt++] = i;
        st[i] = true;
    }
    while(hh!=tt){
        int t = q[hh++];
        if(hh == N) hh = 0;
        st[t] = false;
        for(int i =h[t];i!=-1;i=ne[i]){
            int j = e[i];
            if(dist[j] < dist[t] + w[i] - mid){
                dist[j] = dist[t] + w[i] - mid;
                cnt[j] = cnt[t] + 1;
                // if(++count>10000) return true;
                if(cnt[j]>=N) return true;
                if(!st[j]){
                    q[tt++] = j;
                    if(tt==N) tt = 0;
                    st[j] = true;
                }
            }
        }
    }
    return false;
}

int main(){
    char str[1010];
    while(cin>>m && m){
        memset(h,-1,sizeof h);
        idx = 0;
        for(int i =0;i<m;i++){
            scanf("%s",str);
            int len = strlen(str);
            int left = (str[0]-'a')*26 + (str[1]-'a');
            int right = (str[len-2]-'a')*26 + (str[len-1]-'a');
            add(left,right,len);
        }
        if(!check(0)) {
            puts("No Solution");
            continue;
        }
        double l = 0, r;
        while(true){
            r = check(l);
            if(fabs(r-l)<1e-2) break;
            r = l;
        }
        cout<<r<<endl;
    }
    return 0;
}