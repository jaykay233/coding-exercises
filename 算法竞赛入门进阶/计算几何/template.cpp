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
    Point operator+(Point B) {return Point(x+B.x,y+B.y);}
    Point operator-(Point B) {return Point(x-B.x,y-B.y);}
    Point operator*(double k) {return Point(x*k,y*k);}
    Point operator/(double k) {return Point(x/k,y/k);}
    bool operator == (Point B) {return sgn(x-B.x)==0 && sgn(y-B.y)==0;}
};

double Dot(Vector A, Vector B) {return A.x*B.x + A.y*B.y;}


double Distance(Point A, Point B){
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}

double Dist(Point A, Point B){
    return Distance(A,B);
}

double Len(Vector A) {
    return sqrt(Dot(A,A));
}

double Len2(Vector A){
    return Dot(A,A);
}

double Angle(Vector A,Vector B){
    return acos(Dot(A,B)/Len(A)/Len(B));
}

double Cross(Vector A,Vector B){
    return A.x * B.y - A.y * B.x;
}

double Area2(Point A,Point B,Point C){
    return Cross(B-A,C-A);
}

Vector Rotate(Vector A,double rad){
    return Vector(A.x * cos(rad) - A.y * cin(rad), A.x * sin(rad) + A.y * cos(rad));
}

Vector Normal(Vector A){
    return Vector(-A.y/Len(A),A.x/Len(A));
}

bool Parallel(Vector A,Vector B){
    return sgn(Cross(A,B)) == 0;
}

