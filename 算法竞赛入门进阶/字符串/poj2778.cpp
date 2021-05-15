//ac自动机 + 矩阵快速幂
//大模规通过矩阵快速幂计算可达

#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>
#include <queue>
#define maxn 110
using namespace std;
const int mod = 100000;
int nn,mm;
char st[maxn];
struct Matrix{
    int mo[maxn][maxn],n;
    Matrix(){}
    Matrix(int _n){
        n = _n;
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++)
                mo[i][j] = 0;
        }
    }
};

Matrix mul(Matrix a,Matrix b){
    Matrix res = Matrix(a.n);
    for(int i =0;i<a.n;i++){
        for(int j =0;j<a.n;j++){
            for(int k=0;k<a.n;k++){
                int tmp = (int)a.mo[i][k] * b.mo[k][j] % mod;
                res.mo[i][j] = (res.mo[i][j] + tmp) % mod;
            }
        }
    }
    return res;
}

Matrix powMod(Matrix a,int n){
    Matrix nul;
    nul = Matrix(a.n);
    for(int i =0;i<nul.n;i++){
        nul.mo[i][i] = 1;
    }
    while(n){
        if(n&1) nul = mul(nul,a);
        a = mul(a,a);
        n>>=1;
    }
    return nul;
}

map<char,int> mp;
struct Trie{
    int next[maxn][4],fail[maxn],End[maxn],root,id;
    int newnode(){
        for(int i =0;i<4;i++){
            next[id][i] = -1;
        }
        End[id] = 0;
        return id++;
    }
    void init(int nn){
        mp['A']=0,mp['C']=1,mp['T']=2,mp['G']=3;
        id=0;
        root=newnode();
    }
    void Insert(char* str){
        int now = root;
        int len = strlen(str);
        for(int i =0;i<len;i++){
            if(next[now][mp[str[i]]]==-1){
                next[now][mp[str[i]]] = newnode();
            }
            now = next[now][mp[str[i]]];
        }
        End[now] = 1;
    }

    void build(){
        queue<int> que;
        for(int i =0;i<4;i++){
            if(next[root][i]==-1)
                next[root][i] = root;
            else{
                fail[next[root][i]] = root;
                que.push(next[root][i]);
            }
        }
        while(!que.empty()){
            int now = que.front();
            que.pop();
            for(int i =0;i<4;i++){
                if(next[now][i]==-1)
                    next[now][i] = next[fail[now]][i];
                else{
                    fail[next[now][i]] = next[fail[now]][i];
                    que.push(next[now][i]);
                }
            }
            End[now] |= End[fail[now]];
        }
    }

    Matrix getMatrix(){
        Matrix Mar = Matrix(id);
        for(int i =0;i<id;i++){
            for(int j=0;j<4;j++){
                if(End[next[i][j]]) continue;
                Mar.mo[i][next[i][j]]++;
            }
        }
        return Mar;
    }
}ac;

int main(){
    scanf("%d%d",&nn,&mm);
    ac.init(nn);
    for(int i =0;i<nn;i++){
        scanf("%s",st);
        ac.Insert(st);
    }
    ac.build();
    Matrix M = ac.getMatrix();
    Matrix tmp = powMod(M,mm);
    int res =0 ;
    for(int i =0;i<tmp.n;i++){
        res = (res + tmp.mo[0][i])%mod;
    }
    cout<<res<<endl;
    return 0;
}
