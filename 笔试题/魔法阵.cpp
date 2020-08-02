#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char c[5];
int x[4];
int y[4];
int dis[4][4];
int ptr[4];
int n;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%s",c);
        for(int j=0;j<4;j++){
            x[j] = c[j] - '0';
        }
        scanf("%s",c);
        for(int j =0;j<4;j++){
            y[j] = c[j] - '0';
        }
        for(int j = 0;j<4;j++){
            int max_ = 0;
            for(int k =0;k<4;k++){
                dis[j][k] = (x[j]-x[k])*(x[j]-x[k]) + (y[j]-y[k])*(y[j]-y[k]); 
                if(dis[j][k] > max_){
                    max_ = dis[j][k];
                    ptr[j] = k;
                }
            }
        }
        bool ok = true;
        for(int i =0;i<4;i++){
            int sum_ = 0;
            for(int j =0;j<4;j++){
                if(j==i || j==ptr[i]) continue;
                sum_ += dis[i][j];
            }
            if(sum_ != dis[i][ptr[i]] || ptr[ptr[i]]!=i){
                ok = false;
                break;
            }
        }
        
        if(ok) puts("Yes");
        else puts("No");
     }
    return 0;
}