//ac自动机 + dp
#include <bits/stdc++.h>
#define maxn 105
using namespace std;
int dp[maxn][7000];
char s[500];
const int mod=10007;
int n,m;
struct Trie{
    int next[10000][26],fail[10000],End[10000],id,root;
    int newnode(){
        for(int i=0;i<26;i++){
            next[id][i]=-1;
        }
        End[id]=0;
        return id++;
    }
    void init(){
        id=0;
        root=newnode();
    }
    void Insert(char *str){
        int len=strlen(str);
        int now=root;
        for(int i=0;i<len;i++){
            if(next[now][str[i]-'A']==-1){
                next[now][str[i]-'A']=newnode();
            }
            now=next[now][str[i]-'A'];
        }
        End[now]=1;
    }
    void build(){
        queue<int>que;
        fail[root]=root;
        for(int i=0;i<26;i++){
            if(next[root][i]==-1){
                next[root][i]=root;
            }
            else{
                fail[next[root][i]]=root;
                que.push(next[root][i]);
            }
        }
        while(!que.empty()){
            int now=que.front();
            que.pop();
            for(int i=0;i<26;i++){
                if(next[now][i]==-1){
                    next[now][i]=next[fail[now]][i];
                }
                else{
                    fail[next[now][i]]=next[fail[now]][i];
                    que.push(next[now][i]);
                }
            }
            End[now]|=End[fail[now]];//终点标志也需要转移
        }
    }
}ac;
int powmod(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}
void solve(){
    dp[0][0]=1;
    for(int i=1;i<=m;i++){
        for(int j=0;j<=ac.id;j++){
            if(ac.End[j]) continue;//如果当前位为某一个串的终点
            for(int k=0;k<26;k++){
                if(ac.End[ac.next[j][k]]) continue;
                dp[i][ac.next[j][k]]=(dp[i][ac.next[j][k]]+dp[i-1][j])%mod;
            }
        }
    }
    int res=0;
    for(int i=0;i<=ac.id;i++){
        res=(res+dp[m][i])%mod;
    }
    cout<<(powmod(26,m)-res+mod)%mod<<endl;
}
int main()
{
    scanf("%d%d",&n,&m);
    ac.init();
    while(n--){
        scanf("%s",s);
        ac.Insert(s);
    }
    ac.build();
    solve();
}
