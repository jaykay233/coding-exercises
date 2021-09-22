#include <bits/stdc++.h>
using namespace std;

struct Point{
    double x,y;
    Point(double X=0,double Y=0){x=X,y=Y;}
    Point operator + (Point B) {return Point(x+B.x,y+B.y);}
    Point operator - (Point B) {return Point(x-B.x,y-B.y);}
    Point operator * (double k) {return Point(x*k,y*k);}
    Point operator / (double k) {return Point(x/k,y/k);}
};

typedef Point Vector;
double Cross(Vector A,Vector B){return A.x * B.y - A.y * B.x;}
double Polygon_area(Point* p,int n){
    double area = 0;
    for(int i =0;i<n;i++)
        area += Cross(p[i],p[(i+1)%n]);
    return area/2;
}
Point Polygon_center(Point* p,int n){
    Point ans(0,0);
    if(Polygon_area(p,n) == 0) return ans;
    for(int i =0;i<n;i++)
        ans = ans + (p[i] + p[(i+1)%n]) * Cross(p[i],p[(i+1)%n]);
    return ans /Polygon_area(p,n)/6;
}

int main(){
    int t,n,i;
    Point center;
    Point p[100000];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i =0;i<n;i++) scanf("%lf %lf",&p[i].x,&p[i].y);
        center = Polygon_center(p,n);
        printf("%.2f %.2f\n",center.x,center.y);
    }
    return 0;
}
