//擂台法比较大小,先赋值给其中一个,再修改另一个
#include <bits/stdc++.h>
using namespace std;
int max1 =0 ;
int max2 = 0;
const int N = 1e5+10;
pair<int,int> sum[N];

int get_dist(int x,int y,int x1,int y1){
    return (x-x1)*(x-x1) + (y-y1)*(y-y1);
}

int main(){
    int x1,y1,x2,y2,n;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    scanf("%d",&n);
    
    for(int i =1;i<=n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        int dist1 = get_dist(x,y,x1,y1);
        int dist2 = get_dist(x,y,x2,y2);
        sum[i].first = dist1;
        sum[i].second = dist2;
    }
    sort(sum+1,sum+n+1);
    int min_ = sum[n].first, max_ = -1;
    for(int i=n;i>=1;i--){
        if(sum[i].second>max_){
            max_ = sum[i].second;
        }
        if(sum[i-1].first + max_ < min_){
            min_ = sum[i-1].first + max_;
        }
    }
    
    cout<<min_<<endl;
    
    
    
    return 0;
}