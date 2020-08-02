#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

bool check(int n){
    for(int i =2;i<=sqrt((double)n);i++){
        if(n%i==0) return true;
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    for(int i =2;i<=1e7;i++){
        if(check(i) && check(i+n)){
            cout<<i+n<<" "<<i<<endl;
            break;
        }
    }
    return 0;
}
