#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
int n,m,ok[maxn];
double dp[maxn];
int main(){
    while( cin >> n >> m&&(n+m) )
	{
		for(int i=1;i<=m;i++)
		{
			int l,r; cin >> l >> r;
			ok[l]=r;
		}
		dp[n]=0;
		for(int i=n-1;i>=0;i--)
		{
			dp[i]=0;
			for(int j=1;j<=6;j++)
				if( i+j<=n )	dp[i]+=dp[i+j]/6.0;
				else	dp[i]+=dp[n]/6.0; 
			dp[i]+=1;
			if( ok[i] )	dp[i]=dp[ ok[i] ];
		}
		for(int i=0;i<=n;i++)	ok[i]=0;
		printf("%.4lf\n",dp[0]);
	}
}