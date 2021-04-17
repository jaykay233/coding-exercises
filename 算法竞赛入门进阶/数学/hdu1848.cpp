#include <bits/stdc++.h>
using namespace std;
const int MAX = 1001;
int sg[MAX], s[MAX];
int fibo[15]={1,2,3,5,8,13,21,34,55,89,144,233,377,610,987};

void getSG(){
    for(int i=0;i<=MAX;i++){
        sg[i] = i;
        memset(s,0,sizeof s);
        for(int j=0;j<15 && fibo[j]<=i;j++){
            s[sg[i-fibo[j]]] = 1;
            for(int j=0;j<=i;j++)
                if(!s[j]) {sg[i]=j;break;}
        }
    }
}

int main(){
    getSG();
    int n,m,p;
    while(cin>>n>>m>>p && n + m + p){
        if(sg[n]^sg[m]^sg[p]) cout<<"Fibo"<<endl;
        else cout<<"Nacci"<<endl;
    }
    return 0;
}