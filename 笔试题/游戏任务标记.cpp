#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1025;
bool vis[N];
int main(){
    int a,b;
    cin>>a>>b;
    if(a<1 || a>=N || b<1 || b>=N) cout<<-1<<endl;
    else{
        vis[a] = true; 
        if(vis[b]) cout<<1<<endl;
        else{
            cout<<0<<endl;
        }
    }
    return 0;
}