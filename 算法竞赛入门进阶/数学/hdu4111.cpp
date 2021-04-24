/*
思想：
如果每堆石子数都大于1，那么最后结果肯定相当于所有的堆合并成一堆后，然后再一个一个拿掉的结果。
因为如果那种情况是赢的人一定会不断合并堆来确保他是赢的。又因为所有堆的石子数都大于1，所以输的人无法阻止他这么干。
而有些堆石子数等于1的话，就不一定是所有的合并的结果了，因为输的人可以直接把等于1的堆去掉，就破坏了结构
（合并相当于2步，去掉只需要1步）。
sg[i][j]表示有i个石子数为1的堆数，其它堆合并再取完的步数为j。若值为1则先取者胜，为0为先取者输
 */
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int N=55;
int sg[N][N*1000];
int n,t;
int a[N];
int getsg(int one,int sum)
{
  if(sg[one][sum]!=-1) return sg[one][sum];
  if(sum==1) return sg[one][sum]=getsg(one+1,0);//步数只需要1，放入其他1
  sg[one][sum]=0;
  if(one>=1&&!getsg(one-1,sum))//去掉一个1
  {
    sg[one][sum]=1;
  }
  if(one>=1&&sum&&!getsg(one-1,sum+1))//将一个1合到其他数
  {
    sg[one][sum]=1;
  }
  if(sum>=2&&!getsg(one,sum-1))//非1数减1
  {
    sg[one][sum]=1;
  }
  if(one>=2&&((sum==0&&!getsg(one-2,sum+2))||(sum&&!getsg(one-2,sum+3))))//将两个1合并
  {
    sg[one][sum]=1;
  }
  return sg[one][sum];
}

int main()
{
  memset(sg,-1,sizeof(sg));
  int ca=0;
  scanf("%d",&t);
  while(t--)
  {
    int one=0,sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
      if(a[i]==1)
      {
        one++;//计算1的个数
      }
      else
      {
        sum+=a[i]+1;//计算步数
      }
    }
    if(sum) sum--;//多合并一次
    getsg(one,sum);
    if(sg[one][sum]) printf("Case #%d: Alice\n",++ca);
    else printf("Case #%d: Bob\n",++ca);
  }
  return 0;
}

