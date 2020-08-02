#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;


int main(){
    int n;
    scanf("%d",&n);
    for(int i =1;i<=n;i++){
        int p,num;
        int minx = INT_MIN;
        int maxx = INT_MIN;
        scanf("%d%d",&p,&num);
        for(int i =0;i<num;i++){
            int x;scanf("%d",&x);
            int min_value = min(x-0,p-x);
            int max_value = max(x-0,p-x);
            minx = max(minx,min_value);
            maxx = max(maxx,max_value);
        }
        cout<<minx<<" "<<maxx<<endl;
    }

    return 0;
}