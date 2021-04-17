#include <bits/stdc++.h>
using namespace std;

int n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int l,r;
        cin>>l>>r;
        if(l%(r+1)==0) printf("second\n");
        else printf("first\n");
    }
    return 0;
}