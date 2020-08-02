#include <bits/stdc++.h>
using namespace std;
//最小路径覆盖
//1-2-3路径转化
// 1 \  1'
// 2 \\ 2'
// 3  \ 3'
//路径 = 匹配
//路径终点 = 左部非匹配点 n-m
//等价于让左侧非匹配点最少
//等价于让左侧匹配点最多 m
//等价于找最大匹配 m
//扩展 最小路径重复点覆盖:
//求传递闭包
//g'上求最小路径点覆盖
#include <bits/stdc++.h>
using namespace std;
const int N = 210;
const int M = 30010;
bool d[N][N];
bool st[N];
int n,m;
int match[N];

bool find(int x){
    for(int i =1;i<=n;i++){
        if(d[x][i] && !st[i]){
            st[i] = true;
            int t = match[i];
            if(t==0 || find(t)){
                match[i] = x;
                return true;
            }
        }
    }
    return false;
}


int main(){
    cin>>n>>m;
    for(int i =1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        d[x][y] = true;
    }

    for(int k =1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j =1;j<=n;j++){
                d[i][j] |= d[i][k] & d[k][j];
            }
        }
    }

    long long res = 0;
    for(int i =1;i<=n;i++){
        memset(st,false,sizeof st);
        if(find(i)) res++;
    }
    cout<<n-res<<endl;
    return 0;
}




 