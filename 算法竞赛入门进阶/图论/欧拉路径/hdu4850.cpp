#include <bits/stdc++.h>
using namespace std;

const int maxn = (26*26*26);
const int mod = pow(26,2);
const int maxm = 500005;
bool vis[maxn][26];

int get_next(int now,int i){
    return (now%mod)*26 + i;
}

int cur[maxn];

struct node{
    int n,c;
}st[maxm];

char ans_str[maxm];
int str_len;

void euler(int now){
    int top =0 ;
    memset(cur,0,sizeof cur);
    memset(vis,0,sizeof vis);
    do{
        bool ff = false;
        for(int i=cur[now];i<26;i++){
            if(vis[now][i]) continue;
            vis[now][i] = true;
            cur[now] = i + 1;
            now = get_next(now,i);
            st[++top].n = now;
            st[top].c = i;
            ff=true;
            break;
        }
        if(!ff){
            ans_str[str_len++] = st[top].c + 'a';
            now = st[--top].n;
        }
    }while(top);
}

void init(){
    str_len = 0;
    euler(0);
    for(int i =0;i<3;i++)
        ans_str[str_len++] = 'a';
    ans_str[str_len]= 0 ;
}

int main(){
    init();
    int n;
    while(~scanf("%d",&n)){
        if(n>str_len)
            puts("Impossible");
        else{
            for(int i =0;i<n;i++)
                printf("%c",ans_str[i]);
            puts("");
        }
    }
    return 0;
}