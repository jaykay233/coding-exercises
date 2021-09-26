#include <bits/stdc++.h>
const double pi = acos(-1.0);
const double eps = 1e-8;
const int maxp = 1010;
int sgn(double x);
int Dcmp(double x,double y);
struct Point{
    double x,y;
    Point(){}
    Point(double x,double y):x(x),y(y){}
    Point operator + (Point B) {return Point(x+B.x,y+B.y);}
    Point operator - (Point B) {return Point(x-B.x,y-B.y);}
    Point operator * (double k) {return Point(x*k, y *k);}
    Point operator / (double k) {return Point(x/k, y/k);}
    bool operator == (Point B) {return sgn(x-B.x)==0 && sgn(y-B.y)==0;}
    
};