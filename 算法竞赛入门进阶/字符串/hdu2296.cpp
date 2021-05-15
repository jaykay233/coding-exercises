//hdu2296
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>

#include <iostream>
#include <queue>
#include <cstring>

#define N 1500
using namespace std;

char s[105][105];
int dp[55][N];
string path[55][N];

struct Trie{
    int sz;
    int ch[N][30],val[N],f[N],num[N];
    void init(){
        memset(ch,0,sizeof ch);
        memset(f,0,sizeof f);
        memset(val,0,sizeof val);
        sz =1 ;
    }
    void insert(char *s,int value){
        int len = strlen(s);
        int u = 0;
        for(int i =0;i<len;i++){
            int c = s[i] - 'a';
            if(ch[u][c]==0) ch[u][c]=sz++;
            u = ch[u][c];
        }
        val[u] = value;
    }

    void getfail(){
        queue<int> q;
        int i,u = 0;
        for(i=0;i<26;i++)
            if(ch[u][i]) q.push(ch[u][i]);
        while(!q.empty()){
            u = q.front();q.pop();
            if(val[f[u]]) 
                val[u] += val[f[u]];
            for(int i=0;i<26;i++){
                int v = ch[u][i];
                if(!v) ch[u][i] = ch[f[u]][i];
                else {
                    q.push(v);
                    f[v] = ch[f[u]][i];
                }
            }
        }
    }

    void solve(int n){
        int i,j,k;
        memset(dp,-1,sizeof dp);

        dp[0][0] = 0;
        path[0][0] = "";
        for(int i =0;i<n;i++)
            for(int j=0;j<sz;j++)
                if(dp[i][j]!=-1){
                    for(int k =0;k<26;k++){
                        int u = ch[j][k];
                        if(dp[i][j] + val[u] > dp[i+1][u]){
                            dp[i+1][u] = dp[i][j] + val[u];
                            path[i+1][u] = path[i][j] + (char)(k+'a');
                            continue;
                        }
                        if(dp[i][j] + val[u] == dp[i+1][u]){
                            string str = path[i][j];
                            str.push_back(k+'a');
                            if(str<path[i+1][u]) path[i+1][u] = str;
                        }
                    }
                }
        int ans = 0, row;
        string str;
        for(i=0;i<=n;i++){
            for(j=0;j<sz;j++){
                if(ans < dp[i][j]){
                    dp[i][j] = ans;
                    row = i;
                }
            }
        }

        if(ans == 0)    {
            printf("\n");
            return;
        }
        str = "";
        for(j = 0; j < sz; j++)
            if(dp[row][j] == ans && ( str > path[row][j] || str == "") )
                str = path[row][j];
        cout<<str<<endl;

    }
}Trie;


int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        Trie.init();
        int n,m;
        scanf("%d%d",&n,&m);
        int i;
        for(i=0;i<m;i++)
            scanf("%s",s[i]);
        for(i=0;i<m;i++){
            int x;
            scanf("%d",&x);
            Trie.insert(s[i],x);
        }
        Trie.getfail();
        Trie.solve(n);
    }
    return 0;
}