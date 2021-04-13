#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int n;
long long map[40][40];
int main()
{
    int i,j,cnt=1;;
    while(cin>>n&&n!=-1)
    {
        memset(map,0,sizeof(map));
        for(i=0;i<=n;++i)//先把第一行的每一个数置1，因为迷宫是关于对角线对称的，只要考虑一边，最后乘以2就好
            map[0][i]=1;
        for(i=1;i<=n;++i)
            for(j=0;j<=i;++j)
        {
            if(i==j)
                map[i][j]=map[i][j-1];//在对角线上，前一步只能是从上面走下来
            else
                map[i][j]=map[i-1][j]+map[i][j-1];//不在对角线上，可以从上和左两个方向走
        }
        printf("%d %d %I64d\n",cnt++,n,2*map[n][n]);//cnt是测试样例的序号，n是输入的测试样例，最后一个是步数
    }
    return 0;
}