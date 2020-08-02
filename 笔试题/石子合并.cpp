#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define int long long

signed main(){
    priority_queue<int,vector<int>,greater<int>> q;
    int n;
    cin>>n;
    for(int i =1;i<=n;i++){
        int a;
        cin>>a;
        q.push(a);
    }
    int res= 0 ;
    while(q.size()>=2){
        int a = q.top();q.pop();
        int b = q.top();q.pop();
        res+=a*b;
        q.push(a+b);
    }
    cout<< res << endl;

    return 0;
}