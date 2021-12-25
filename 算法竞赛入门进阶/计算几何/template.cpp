#include <iostream>
#include "template.h"
#include <cmath>
int sgn(double x){
    if(fabs(x)<eps) return 0;
    else return x < 0?-1:1;
}

int dcmp(double x,double y){
    if(fabs(x-y)<eps) return 0;
    else return x<y?-1:1;
}

struct Point{
    double x,y;
    Point() {}
    Point(double x,double y):x(x),y(y) {}
};

double Distance(Point A, Point B){
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}

double Dist(Point A, Point B){
    return Distance(A,B);
}