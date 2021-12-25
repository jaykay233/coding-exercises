#include <bits/stdc++.h>
using namespace std;
const int MAXL=1000000;
string s;
int n =0, len,st;
int maxlen[2*MAXL+10], minlen[2*MAXL+10],trans[2*MAXL+10][26],slink[2*MAXL+10];

int new_state(int _maxlen, int _minlen,int* _trans, int _slink){
    maxlen[n] = _maxlen;
    minlen[n] = _minlen;
    for(int i =0;i<26;i++){
        if(_trans == nullptr)
            trans[n][i] = -1;
        else
            trans[n][i] = _trans[i];
    }
    slink[n] = _slink;
    return n++;
}

int add_char(char ch,int u){
    int c = ch - 'a';
    int z = new_state(maxlen[u] + 1, -1, NULL, -1);
    int v = u;
    while(v!=-1 && trans[v][c] == -1){
        trans[v][c] = z;
        v = slink[v];
    }
    if(v==-1){
        minlen[z] = 1;
        slink[z] = 0;
        return z;
    }
    int x = trans[v][c];
    if(maxlen[v] + 1 == maxlen[x]){
        minlen[z] = maxlen[x] + 1;
        slink[z] = x;
        return z;
    }
    int y = new_state(maxlen[v]+1,-1,trans[x],slink[x]);
    slink[y] = slink[x];
    minlen[x] = maxlen[y] + 1;
    slink[x] = y;
    minlen[z] = maxlen[y] + 1;
    slink[z] = y;
    int w = v;
    while(w!=-1 && trans[w][c] == x){
        trans[w][c] = y;
        w = slink[w];
    }
    minlen[y] = maxlen[slink[y]] + 1;
    return z;
}

