#include <bits/stdc++.h>
using namespace std;
const int N = 1010,M = 510;
int n,m;
int h[N],e[M],ne[M];
int idx,top,timestamp;
int dfn[N],low[N],stk[N];
int root,dcc_cnt;
vector<int> dcc[N];
bool cut[N];
void add(int a,int b){
    e[idx] = b;ne[idx] = h[a];h[a] = idx++;
}

void tarjan(int u){
    dfn[u] = low[u] = ++timestamp;
    stk[++top] = u;
    if(u==root && h[u]==-1){
        dcc_cnt++;
        dcc[dcc_cnt].push_back(u);
        return;
    }
    
    int cnt = 0;
    for(int i =h[u];i!=-1;i=ne[i]){
        int j = e[i];
        if(!dfn[j]){
            tarjan(j);
            low[u] = min(low[u],low[j]);
            if(dfn[u] <= low[j]){
                cnt++;
                if(u!=root || cnt>1) cut[u] = true;
                ++dcc_cnt;
                int y;
                do{
                    y = stk[top--];
                    dcc[dcc_cnt].push_back(y);
                }while(y!=j);
                dcc[dcc_cnt].push_back(u);
            }
        }
        else low[u] = min(low[u],dfn[j]);
    }

}


int main(){
    int T = 1;
    while(cin>>m && m){
        for(int i =1;i<=dcc_cnt;i++) dcc[i].clear();
        idx = n = timestamp = top = dcc_cnt = 0;
        memset(h,-1,sizeof h);
        memset(dfn,0,sizeof dfn);
        memset(cut,0,sizeof cut);

        while(m--){
            int a,b;
            cin>>a>>b;
            n = max(n,a);n = max(n,b);
            add(a,b);add(b,a);
        }

        for(root=1;root<=n;root++){
            if(!dfn[root])
                tarjan(root);
        }

        int res =0 ;
        long long num = 1;
        for(int i=1;i<=dcc_cnt;i++){
            int cnt =0 ;
            for(int j =0;j<dcc[i].size();j++)
                if(cut[dcc[i][j]])
                    cnt++;
            
            if(cnt==0) res+=2,num*=dcc[i].size()*(dcc[i].size()-1)/2;
            else if(cnt==1) res++,num*=dcc[i].size()-1;
        }
        printf("Case %d: %d %llu\n", T ++, res, num);
    }

    return 0;
}