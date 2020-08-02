#include <bits/stdc++.h>
using namespace std;
long long n,m,k;
vector<pair<long long,long long>> points;
struct circle{
    long long r,x,y;
};
vector<circle> circles;
const int N = 2010;
int num[N][N];

long long dist_square(long long a,long long b,long long c,long long d){
    return (a-c)*(a-c) + (b-d)*(b-d);
}

int main(){
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i =0;i<n;i++){
        long long a,b;
        scanf("%lld%lld",&a,&b);
        points.push_back({a,b});
    }
    for(int i =0;i<m;i++){
        long long a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        circles.push_back({a,b,c});
    }
    
    for(int i=0;i<n;i++){
        for(int j =0;j<m;j++){
            long long d = dist_square(points[i].first,points[i].second,circles[j].x,circles[j].y);
            if(d < circles[j].r * circles[j].r){
                num[i][j] = 1;
            }
        }
    }
    for(int i =0;i<k;i++){
        long long a,b;
        scanf("%lld%lld",&a,&b);
        a--;b--;
        long long res =0;
        for(int j =0;j<m;j++){
            if(num[a][j] != num[b][j]) res++;
        }
        printf("%lld\n",res);
    }

    return 0;
}