#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
struct pp
{
    string name;   
    int cost;   
    int dead;   
}ss[20];    
struct ps
{
    int fa,zj,soce,time;
}dp[1<<15]; 
int main()
{
    ios::sync_with_stdio(false);    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        memset(dp,0,sizeof(dp));   
        for(int i=0;i<n;i++)
            cin>>ss[i].name>>ss[i].dead>>ss[i].cost;   
        int end=1<<n;       
        for(int i=1;i<end;i++)       
        {   dp[i].soce=inf;                  
            for(int j=n-1;j>=0;j--)   
            {
                int temp=1<<j;   
                if(temp&i)   
                {   int tem=i-temp;   
                    int tt=dp[tem].time+ss[j].cost-ss[j].dead;
                    if(tt<0)   tt=0;
                    if(tt+dp[tem].soce<dp[i].soce)  
                    {
                        dp[i].soce=tt+dp[tem].soce;  
                        dp[i].fa=tem;   
                        dp[i].zj=j;   
                        dp[i].time=dp[tem].time+ss[j].cost;   
                    }

                }
            }
        }
        cout<<dp[end-1].soce<<endl; 
        stack<int>q;  
        int tt=end-1;;
        while(dp[tt].time)
        {
            q.push(dp[tt].zj);
            tt=dp[tt].fa;
        }
        while(!q.empty())
        {
            int k=q.top();
            cout<<ss[k].name<<endl;
            q.pop();

        }

    }
    return 0;
}