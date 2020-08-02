#include <iostream>
#include <cstdio>
using namespace std;
int t;
int n,x,a,b;

int main(){
    cin>>t;
    for(int i =0;i<t;i++){
        cin>>n>>x>>a>>b;
        int r = abs(b-a)+x;
        cout<<min(r,n-1)<<endl;
    }
    
    return 0;
}