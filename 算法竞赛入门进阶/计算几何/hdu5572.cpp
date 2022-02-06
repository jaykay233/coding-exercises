#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
int sgn(double x){
    if(fabs(x)<eps) return 0;
    else return x <0?-1:1;
}

struct Point{
    double x,y;
    Point() {}
    Point(double x,double y):x(x),y(y){}
    Point operator + (Point B) {return Point(x+B.x, y+B.y);}
    Point operator - (Point B) {return Point(x-B.x, y-B.y);}
    Point operator * (double k) {return Point(x*k,y*k);}
    Point operator / (double k) {return Point(x/k, y/k);}
};

typedef Point Vector;
double Dot(Vector A,Vector B) {return A.x * B.x + A.y * B.y;}
double Len(Vector A) {return sqrt(Dot(A,A));}
double Len2(Vector A) { return Dot(A,A);}
double Cross(Vector A, Vector B) { return A.x * B.y - A.y * B.x;}
double Distance(Point A,Point B) {return hypot(A.x-B.x, A.y - B.y);}
struct Line{
    Point p1,p2;
    Line() {}
    Line(Point p1,Point p2):p1(p1),p2(p2){}
};

typedef Line Segment;
int Point_line_relation(Point p,Line v){
    int c = sgn(Cross(p-v.p1,v.p2-v.p1));
    if(c<0) return 1;
    if(c>0) return 2;
    return 0;
}

double Dis_point_line(Point p,Line v){
    return fabs(Cross(p-v.p1,v.p2-v.p1))/Distance(v.p1,v.p2);
}

double Dis_point_seg(Point p, Segment v){
    if(sgn(Dot(p-v.p1,v.p2-v.p1)) < 0 || sgn(Dot(p-v.p2, v.p1-v.p2))<0 )
        return min(Distance(p,v.p1), Distance(p,v.p2));
    return Dis_point_line(p,v);
}

Point Point_line_proj(Point p, Line v){
    double k = Dot(v.p2 - v.p1, p - v.p1)/Len2(v.p2-v.p1);
    return v.p1 + (v.p2 - v.p1) * k;
}

Point Point_line_symmetry(Point p, Line v){
    Point q = Point_line_proj(p,v);
    return Point(2*q.x-p.x, 2*q.y-p.y);
}

struct Circle{
    Point c;
    double r;
    Circle(){}
    Circle(Point c,double r):c(c),r(r){}
    Circle(double x,double y,double _r){c=Point(x,y);r=_r;}
};

int Seg_circle_relation(Segment V, Circle C){
    double dst = Dis_point_seg(C.c, V);
    if(sgn(dst-C.r) < 0) return 0;
    if(sgn(dst-C.r) ==0) return 1;
    return 2;
}

int Line_circle_relation(Line v, Circle C){
    double dst = Dis_point_line(C.c,v);
    if(sgn(dst - C.r) < 0) return 0;
    if(sgn(dst - C.r) ==0) return 1;
    return 2;
}

int Line_cross_circle(Line v,Circle C, Point& pa, Point& pb){
    if(Line_circle_relation(v,C)==2) return 0;
    Point q = Point_line_proj(C.c, v);
    double d = Dis_point_line(C.c, v);
    double k = sqrt(C.r*C.r - d*d);
    if(sgn(k) == 0){
        pa = q;
        pb = q;
        return 1;
    }
    Point n = (v.p2 - v.p1) / Len(v.p2 - v.p1);
    pa = q + n * k;
    pb = q - n * k;
    return 2;
}




int main(){
    int T;scanf("%d",&T);
    for(int cas=1;cas <= T;cas++){
        Circle O; Point A,B,V;
        scanf("%lf%lf%lf",&O.c.x, &O.c.y, &O.r);
        scanf("%lf%lf%lf%lf",&A.x,&A.y,&V.x,&V.y);
        scanf("%lf%lf",&B.x,&B.y);
        Line l(A,A+V);
        Line t(A,B);
        if(Point_line_relation(B,l) == 0 && Seg_circle_relation(t,O)>=1 && sgn(Cross(B-A,V))==0)   
            printf("Case # %d:Yes\n", cas);
        else{
            Point pa,pb;
            if(Line_cross_circle(l,O,pa,pb)!=2)
                printf("Case # %d: No\n", cas);
            else{
                Point cut;
                if(Distance(pa,A) > Distance(pb,A)) cut = pb;
                else cut = pa;
                Line mid(cut,O.c);
                Point en = Point_line_symmetry(A,mid);
                Line light(cut, en);
                if(Distance(light.p2,B) > Distance(light.p1,B))
                    swap(light.p1, light.p2);
                if(sgn(Cross(light.p2 - light.p1, Point(B.x-cut.x, B.y - cut.y)))==0 )
                    printf("Case # %d: Yes\n", cas);
                else   
                    printf("Case # %d: No\n", cas);
            }
        }
    }
    return 0;
}