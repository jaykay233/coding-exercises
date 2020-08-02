#include <bits/stdc++.h>
using namespace std;
int n,i,j;

int dfs(int n,int i,int j){
    if(i==1) return j;
    if(j==n) return n + i -1;
    if(i==n) return 3*n-j-1;
    if(j==1) return 4*n-i-2;
    return dfs(n-2,i-1,j-1) + 4*(n-1);
}

int main(){
    scanf("%d%d%d",&n,&i,&j);
    cout<<dfs(n,i,j)<<endl;
    return 0;
}