#include <bits/stdc++.h>
using namespace std;
int T;
int N;
typedef long long ll;
int main(){
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        int n;
        scanf("%d",&n);
        ll sum = 0;
        int maxx = -99999999;
        int num;
        for(int i =0;i<n;i++){
            scanf("%d",&num);
            sum += num;
            if(num>maxx)
                maxx = num;
        }
        if(sum - maxx + 1 >= maxx)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}