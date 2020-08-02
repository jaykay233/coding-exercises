// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
using namespace std;
const int N = 30;
const int M = N * N/2;
int match[N];
int match2[N];
int h[N],e[M],ne[M],idx;
bool st[N];
int n;
int xmin[N],ymin[N],xmax[N],ymax[N];
int x[N],y[N];
void add(int a,int b){
    e[idx] =b;ne[idx]=h[a];h[a] = idx++;
}

bool contain(int i,int j){
    if(x[j]>xmin[i] && x[j]<xmax[i] && y[j]>ymin[i] && y[j]<ymax[i]) return true;
    return false;
}

void clear(){
    memset(h,-1,sizeof h);
    memset(match,-1,sizeof match);
    idx =0 ;
}

bool dfs(int x){
    for(int i =h[x];i!=-1;i=ne[i]){
        int j = e[i];
        if(!st[j]){
            st[j] = true;
            if(match[j]==-1 || dfs(match[j])){
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}


int main(){
    int T =0;
    while(scanf("%d",&n) && n){
        T++;
        for(int i =0;i<n;i++){
            scanf("%d%d%d%d",&xmin[i],&xmax[i],&ymin[i],&ymax[i]);
        }
        for(int i =0;i<n;i++){
            scanf("%d%d",&x[i],&y[i]);
        }

        clear();
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(contain(i,j)) add(i,j+n);
            }
        }
        int res =0 ;
        for(int i =0;i<n;i++){
            memset(st,false,sizeof st);
            if(dfs(i)) res++;
        }
        if(res<n) {
            printf("none\n");
            continue;
        }
        
        int match_count = 0;
        vector<pair<int,int> > edges;
        for(int u =0;u<n;u++){
            for(int v=0;v<n;v++){
                if(contain(u,v)){
                    clear();
                    for(int i =0;i<n;i++){
                        for(int j =0;j<n;j++){
                            if( i==u && j ==v) continue;
                            if(contain(i,j)){
                                add(i,j+n);
                            }
                        }
                    }
                    int res= 0 ;
                    for(int i =0;i<n;i++){
                        memset(st,false,sizeof st);
                        if(dfs(i)) res++;
                    }
                    if(res<n) {
                        ++match_count;
                        edges.push_back({u,v});
                    }
                }
            }
        }
        

        printf("Heap %d\n",T);
        if(edges.empty()){
            printf("none\n");
            continue;
        }


        for(int i =0;i<edges.size();i++){
            char c = edges[i].first + 'A';
            int d = edges[i].second+1;
            printf("(%c,%d)",c,d);
            if(i!=edges.size()-1){
                printf(" ");
            }else{
                printf("\n\n");
            }
        }
    }

    return 0;
}