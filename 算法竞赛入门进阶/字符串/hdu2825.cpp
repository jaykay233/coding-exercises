#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int tn,ch[111][26],fail[111],flag[111];

void insert(char *s,int k){
    int x =0 ;
    for(int i =0;s[i];++i){
        int y = s[i] - 'a';
        if(ch[x][y]==0) ch[x][y] = ++tn;
        x = ch[x][y];
    }
    flag[x] |= 1<<k;
}

void init(){
    memset(fail,0,sizeof fail);
    queue<int> que;
    for(int i=0;i<26;i++){
        if(ch[0][i]) que.push(ch[0][i]);
    }
    while(!que.empty()){
        int x = que.front();que.pop();
        for(int i =0;i<26;i++){
            if(ch[x][i]) que.push(ch[x][i]),fail[ch[x][i]]=ch[fail[x]][i],flag[ch[x][i]] |= flag[ch[fail[x]][i]];
            else ch[x][i] = ch[fail[x]][i];
        }
    }
}

int getCnt(int s){
    int res =0 ;
    for(int i =0;i<10;i++){
        if(s>>i&1) ++ res;
    }
    return res;
}

int d[26][111][1<<10];


int main(){
    char str[11];
    int n,m,k;
    while(~scanf("%d%d%d",&n,&m,&k) && (n||m||k)){
        tn = 0;
        memset(ch,0,sizeof ch);
        memset(flag,0,sizeof flag);
        for(int i =0;i<m;++i){
            scanf("%s",str);
            insert(str,i);
        }
        init();
        memset(d,0,sizeof d);
        d[0][0][0]=1;
        for(int i =0;i<n;i++){
            for(int j=0;j<=tn;j++){
                for(int k=0;k<(1<<m);k++){
                    if(d[i][j][k]==0) continue;
                    for(int y=0;y<26;y++){
                        d[i+1][ch[j][y]][k|flag[ch[j][y]]] += d[i][j][k];
                        d[i+1][ch[j][y]][k|flag[ch[j][y]]] %= 20090717;
                    }
                }
            }
        }
        int res =0;
        for(int i=0;i<=tn;i++){
            for(int j=0;j<(1<<m);j++){
                if(getCnt(j)<k) continue;
                res += d[n][i][j];
                res %= 20090717;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}