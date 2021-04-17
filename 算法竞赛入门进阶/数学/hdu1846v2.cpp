#include <bits/stdc++.h>
using namespace std;
const int MAX = 1001;
int n,m,sg[MAX],s[MAX];

void getSG(){
    memset(sg,0,sizeof sg);
    for(int i=1;i<=n;i++){
        memset(s,0,sizeof s);
        for(int j=1;j<=m && i-j>=0;j++){
            s[sg[i-j]] = 1;
        }
        for(int j=0;j<=n;j++){
            if(!s[j]) {sg[i]=j;break;}
        }
    }
}

int main(){
    int c;cin>>c;
    while(c--){
        cin>>n>>m;
        getSG();
        if(sg[n]) cout<<"first\n";
        else cout<<"second\n";
    }
    return 0;
}