#include <bits/stdc++.h>
using namespace std;
//求ax+by=gcd(a,b)的解

void extend_gcd(int a,int b,int& x,int& y){
    if(b==0){
        x=1,y=0;
        return;
    }
    extend_gcd(b,a%b,x,y);
    int tmp = x;
    x = y;
    y = tmp - (a/b)*y;
}

int main(){
    int a = 3,b=4;
    int x,y;
    extend_gcd(a,b,x,y);
    printf("%d %d\n",x,y);
    return 0;
}