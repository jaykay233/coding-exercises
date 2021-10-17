#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 5;
char str[MAXN], pattern[MAXN];
int Next[MAXN];
int cnt;
int getFail(char* p,int plen){
    Next[0] = 0;
    Next[1] = 0;
    for(int i=1;i<plen;i++){
        int j = Next[i];
        while(j && p[i]!=p[j]) j = Next[j];
        Next[i+1] = (p[i] == p[j]) ? j+1:0;
    }
}

int kmp(char* s,char* p){
    int last = -1;
    int slen = strlen(s), plen = strlen(p);
    getFail(p,plen);
    int j =0;
    for(int i =0;i<slen;i++){
        while(j && s[i]!=p[j]) j = Next[j];
        if(s[i] == p[j]) j++;
        if(j == plen){
            if(i - last >= plen){
                cnt ++;
                last = i;
            }
        }
    }
}




