#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main(){
    int l = -90 , r = 90;
    int n;
    cin>>n;
    string res;
    int mid;
    while(l<r && res.size()<6){
        if(n<0) mid = -((-(l+r))>>1);
        else mid = (l + r)>>1;
        if(n>=mid) {
            res+="1";
            l = mid;
        }else{
            res+="0";
            r = mid;
        }
        // cout<<l<<" "<<r<<endl;
    }
    cout<<res<<endl;
    return 0;
}