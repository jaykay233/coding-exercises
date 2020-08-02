#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL mod=998244353;
const int N=1e4+10,M=210;
int a[N];
LL f[N][M][3],s1[M],s2[M];//s1为0、1、2的前缀和、s2为0和1的前缀和

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    //针对a[1]、a[2]进行初始化(a[1]和a[2]之间只有两种情况出现)
    for(int i=(a[1]?a[1]:1);i<=(a[1]?a[1]:200);i++)
    {
        for(int j =(a[2]?a[2]:1);j<=(a[2]?a[2]:200);j++)
        {
            if(i==j) f[2][j][1]++;
            else if(i<j) f[2][j][2]++;
        }
    }
    //初始化s1和s2(i=2的前缀和)
    for(int j=1;j<=200;j++)
    {
        s1[j]=s1[j-1]+f[2][j][0]+f[2][j][1]+f[2][j][2];
        s2[j]=s2[j-1]+f[2][j][0]+f[2][j][1];
    }

    //开始递推
    for(int i=3;i<=n;i++)
    {
        for(int j=(a[i]?a[i]:1);j<=(a[i]?a[i]:200);j++)
        {
            f[i][j][0]=(s2[200]-s2[j])%mod;
            f[i][j][1]=(f[i-1][j][0]+f[i-1][j][1]+f[i-1][j][2])%mod;
            f[i][j][2]=s1[j-1]%mod;
        }
        //每次i循环更新s1和s2
        for(int j=1;j<=200;j++)
        {
            s1[j]=s1[j-1]+f[i][j][0]+f[i][j][1]+f[i][j][2];
            s2[j]=s2[j-1]+f[i][j][0]+f[i][j][1];
        }
    }

    LL res=0;

    for(int j=(a[n]?a[n]:1);j<=(a[n]?a[n]:200);j++)
    {
        res=(res+f[n][j][0]+f[n][j][1])%mod;
    }

    cout<<res<<endl;
    return 0;

}