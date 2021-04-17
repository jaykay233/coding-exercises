#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 130;
int n;//总过(1<<n)个队伍
double G[maxn][maxn];//存放各个队伍间的胜率关系 G[i][j]即队伍i击败队伍j的概率
double dp[maxn][maxn];//dp[i][j]表示在第i轮第j只球队获胜的概率

void DP()
{
    for(int i = 0;i < (1<<n);i++)//算出每个队伍第0场的胜率，都为1.0
    {
        dp[0][i] = 1.0;
    }
    for(int i = 1;i <= n;i++)//决出冠军最多的轮数，一棵二叉树的深度-1
    {
        for(int j = 0; j < (1<<n);j++)//遍历每个队伍，计算出当前轮次的胜率
        {
            dp[i][j]= 0.0;//注意别忘了这个init
            for(int k = 0; k < (1<<n);k++)//遍历可能交手的队伍
            {
                if(j == k)
                {
                    continue;//自己与自己不交手
                }
                //关键部分，j和k在决赛轮相遇，而在决赛轮之前它们是不会遇见的，即j和k是来自两个不同的小组的队伍
                if(((j / (1<<i)) == (k / (1<<i)) ) && ( j /(1<<(i-1))  != (k / (1<<(i-1))) ) )
                {
                    dp[i][j] += dp[i-1][j] * dp[i-1][k] * G[j][k];
                    // j上一轮获胜的概率  *  k上一轮获胜的概率 * 最后一轮j战胜k的概率
                }
            }
        }
    }
}

int main()
{
    while((scanf("%d",&n)&& n != -1))
    {
        for(int i =0 ;i< (1<<n);i++)
        {
            for(int j = 0;j < (1<<n);j++)
            {
                scanf("%lf",&G[i][j]);
            }
        }
        DP();
        int ans = 0;//保存胜率最大的队伍编号
        for(int j = 1 ;j < (1<<n);j++)//遍历每一只队伍
        {
            if(dp[n][ans] < dp[n][j])//更新胜率大的队伍
            {
                ans = j;
            }
        }
        cout<<ans+1<<endl;
    }
    return 0;
}