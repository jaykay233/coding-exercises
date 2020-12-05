#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int l[maxn];
int s;
int sta[maxn*10];

void search(int v,int m){
    int w;
    while(l[v]<10){
        int w=v*10+l[v];
        l[v]++;
        sta[s++]=w;
         v=w%m;
    }
    for(int i=0;i<s;i++){
        cout<<sta[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int m = 10;
    search(0,10);
    return 0;
}