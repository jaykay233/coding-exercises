//extend[i]表示T与S[i,n-1]的最长公共前缀，要求出所有extend[i](0<=i<n)。
//next[i]表示T[i,m-1]和T的最长公共前缀长度
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int Next[maxn], ex[maxn];

void GetNext(char* str){
    int i=0,j,po,len = strlen(str);
    Next[0] = len;
    while(str[i] == str[i+1] && i+1<len) i++;
    Next[1] = i;
    po = 1;
    for(i=2;i<len;i++){
        if(Next[i-po] + i < Next[po] + po)
            Next[i] = Next[i-po];
        else{
            j = Next[po] + po - i;
            if(j<0) j =0;
            while(i+j<len && str[j] == str[j+i])
                j++;
            Next[i] = j;
            po = i;
        }
    }
}

void EXKMP(char* s1,char* s2){
    int i=0,j,po,len=strlen(s1), l2=strlen(s2);
    GetNext(s2);
    while(s1[i]==s2[i] && i<l2 && i<len) i++;
    ex[0] = i;
    po = 0;
    for(i=1;i<len;i++){
        if(Next[i-po] + i<ex[po] + po) ex[i] = Next[i-po];
        else{
            j = ex[po] + po - i;
            if(j<0) j =0 ;
            while(i+j<len && j<l2 && s1[j+i]==s2[j]) j++;
            ex[i] = j;
            po = i;
        }
    }
}


int main(){


    return 0;
}