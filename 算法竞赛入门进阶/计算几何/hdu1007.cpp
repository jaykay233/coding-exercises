#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
const double INF = 1e20;
const double eps = 1e-8;
struct Point{
    double x,y;
};

double Distance(Point A,Point B){
    return hypot(A.x-B.x, A.y-B.y);
}

int sgn(double x){
    if(fabs(x)<eps) return 0;
    return x<0?-1:1;
}

bool cmpxy(Point A,Point B){
    return sgn(A.x-B.x) < 0 || sgn(A.x - B.x)==0 && sgn(A.y-B.y)<0;
}

bool cmpy(Point A, Point B){
    return sgn(A.y - B.y) < 0;
}

Point p[MAXN], tmp_p[MAXN];

double Closest_Pair(int left, int right){
    double dis=INF;
    if(left == right) return dis;
    if(left+1 == right)
        return Distance(p[left], p[right]);
    int mid = (left + right) >> 1;
    double d1 = Closest_Pair(left, mid);
    double d2 = Closest_Pair(mid+1, right);
    dis = min(d1,d2);
    int k =0 ;
    for(int i = left;i <= right; i++)
        if(fabs(p[mid].x - p[i].x) <= dis)
            tmp_p[k++] = p[i];

    sort(tmp_p, tmp_p + k, cmpy);
    for(int i =0;i<k;i++)
        for(int j=i+1;j<k;j++){
            if(tmp_p[j].y - tmp_p[i].y >= dis) break;
            dis = min(dis, Distance(tmp_p[i], tmp_p[j]));
        }
    return dis;
}


int main(){
    int n;
    while(~scanf("%d",&n) && n){
        for(int i =0;i<n;i++) scanf("%lf%lf",&p[i].x, &p[i].y);
        sort(p,p+n,cmpxy);
        printf("%.2f\n", Closest_Pair(0,n-1)/2);
    }
    return 0;
}