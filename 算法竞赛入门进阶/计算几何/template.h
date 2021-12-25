#include <iostream>
#include <cmath>
const double pi = acos(-1.0);
const double eps = 1e-8;

int sgn(double x);
int dcmp(double x,double y);
struct Point;

double Distance(Point, Point);
double Dist(Point, Point);
typedef Point Vector;
double Dot(Point ,Point);
double Len(Vector);
double Len2(Vector);
double Angle(Vector, Vector);
double Cross(Vector, Vector);
double Area2(Point, Point, Point);
Vector Rotate(Vector, Vector);
Vector Normal(Vector);
bool Parallel(Vector, Vector); 

struct Line;
typedef Line Segment;

bool Point_on_seg(Point, Line);

double Dis_point_line(Point,Line);
Point Point_line_proj(Point,Line);