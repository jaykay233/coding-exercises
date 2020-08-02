#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int N,M;
#define MAXN 1010
#define MAXM 10010
int e[MAXM],ne[MAXM],head[MAXN],de[MAXN];
int idx;
bool flag[MAXM];
vector<int> ans;

void add_edge(int x,int y){
    e[idx]  =y; ne[idx] = head[x] ; head[x] = idx++;
}

void dfs(int x){
    for(int i = head[x];i!=-1;i=ne[i]){
        int j = e[i];
        int c = i/2;
        if(flag[c]) continue;
        flag[c] = true;
        dfs(j);
        ans.push_back(c);
    }
}


int main(){
    memset(head,-1,sizeof(head));
    while(cin>>N && N){
        cin>>M;
        int a,b;
        for(int i=1;i<=M;i++){
            cin>>a>>b;
            add_edge(a,b);
            add_edge(b,a);
            de[a]++;de[b]++;
        }

        bool ok = true;
        for(int i=1;i<=N;i++){
            if(de[i]%2) {
                ok = false;
                break;
            }
        }
        if(!ok) {
            cout<<0<<endl;
            continue;
        }

        for(int i=1;i<=N;i++){
            if(head[i]!=-1) {
                dfs(i);break;
            }
        }

        if(ans.size()!=M){
            cout<<0<<endl;
            continue;
        }

        cout<<1<<endl;
    }

    return 0;
}