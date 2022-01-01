#include <bits/stdc++.h>
using namespace std;
const int maxn = 104;
const double eps = 1e-8;
const int N = 2e5+5;
bool vis[N];
int ans[N];
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
    bool operator == (Point B) const {return sgn(x-B.x) == 0 && sgn(y-B.y)==0;}
    bool operator <(Point B) const  {
        return sgn(x-B.x)<0 || (sgn(x-B.x)==0 && sgn(y-B.y) < 0);
    }
}p[N], ch[N];
int n;

typedef Point Vector;
double Cross(Vector A,Vector B){
    return A.x * B.y - A.y * B.x;
}

double Distance(Point A,Point B){
    return hypot(A.x-B.x,A.y-B.y);
}


int ConvexHull(Point* p,int n, Point* ch){
    int m = 0;
    for(int i =0;i<n;i++){
        if(i>0 && p[i].x == p[i-1].x) continue;
        while(m>1 && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]) > 0) m--;
        ch[m++] = p[i];
    }
    return m;
}


int main(){
    int t; scanf("%d",&t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0;i<n;i++){
            scanf("%lf%lf",&p[i].x,&p[i].y);
            p[i].id = i;
        }
        sort(p,p+n);
        int m = ConvexHull(p,n,ch);
        memset(vis,0,sizeof vis);
        vis[0] = vis[m-1] = 1;
        ans[0] = 1; ans[m-1]=n;
        for(int i = 1;i < m-1;i++) if(Cross(ch[i]-ch[i-1],ch[i+1] - ch[i-1])!=0 ) vis[i] =1;

        for(int i = m-2;i>0;i--){
            if(vis[i]) ans[i] = ch[i].id;
            else ans[i] = min(ans[i+1], ch[i].id);
        }

        for(int i =0;i<m-1;i++) if(ans[i]==ch[i].id) printf("%d",ans[i]); 
    }
    return 0;
}