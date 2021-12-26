#include <bits/stdc++.h>
using namespace std;
const int maxn = 104;
const double eps = 1e-8;
const int N = 2e5+5;
int sgn(double x){
    if(fabs(x) < eps) return 0;
    else return x < 0?-1:1;
}

struct Point{
    double x,y;
    int id =0;
    Point() {}
    Point(double x,double y):x(x),y(y) {}
    Point operator + (Point B) {return Point(x+B.x,y+B.y);}
    Point operator - (Point B) {return Point(x-B.x, y - B.y);}
    bool operator == (Point B) {return sgn(x-B.x) == 0 && sgn(y-B.y)==0;}
    bool operator < (Point B) {
        return sgn(x-B.x)<0 || (sgn(x-B.x)==0 && sgn(y-B.y) < 0);
    }
}p[N], ans[N];
int n;

typedef Point Vector;
double Cross(Vector A,Vector B){
    return A.x * B.y - A.y * B.x;
}

double Distance(Point A,Point B){
    return hypot(A.x-B.x,A.y-B.y);
}

int Convex_hull(Point* p, int n,Point* ch){
    sort(p,p+n);
    n = unique(p,p+n) - p;
    int j = n - 1;
    int v =0 ;
    ch[v++] = p[j];
    for(int i = n-2; i>=0;i--){
        while(v>1 && sgn(Cross(ch[v-1]-ch[v-2],p[i] - ch[v-2]))<=0 )
            v--;
        ch[v++] = p[i];
    }
    return v;
}

int main(){
    int t; scanf("%d",&t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0;i<n;i++){
            scanf("%lf%lf",&p[i].x,&p[i].y);
            p[i].id = i;
        }
        int v = Convex_hull(p,n,ans);
        for(int i =0;i<v-1;i++)
            printf("%d ",ans[i].id);
        printf("%d\n", ans[v-1].id);
    }

    return 0;
}