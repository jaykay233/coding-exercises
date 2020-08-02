#include <bits/stdc++.h>
#define mod 1000000007
#define eps 1e-6
#define ll long long
#define INF 0x3f3f3f3f
#define ME0(x) memset(x,0,sizeof(x))
using namespace std;
int T,n,m;
int isprime[10005];//素数表
int vis[10005];//标记
struct node
{
    int num,money;
    bool operator <(const node &c) const//步数小的先出队
    {
        return money>c.money;
    }
} now,next;
void eratos(int x)//求素数表
{
    for(int i=0; i<=x; ++i)
        isprime[i]=true;
    isprime[0]=isprime[1]=false;
    for(int i=2; i<=x; ++i)
    {
        if(isprime[i])
        {
            int j=i+i;
            while(j<=x)
            {
                isprime[j]=false;
                j+=i;
            }
        }
    }
}
void bfs()
{
    priority_queue<node>q;
    now.num=n,now.money=0;
    q.push(now);
    vis[n]=1;
    int f=0;
//    cout<<now.num<<endl;
//    cout<<2<<endl;
    while(!q.empty())
    {
        char x[5];
//        cout<<1<<endl;
        now=q.top();
        q.pop();
        if(now.num==m)
        {
            f=1;
            cout<<now.money<<endl;
            return;
        }
        for(int i=0; i<4; ++i)
        {
            sprintf(x,"%d",now.num);
            for(int j=0; j<10; ++j)
            {
                if(i==0&&j==0)//千位不允许为0
                    continue;
                if(i==0)//四种情况，分别针对"个十百千"位的变换
                    next.num=j*1000+(x[1]-'0')*100+(x[2]-'0')*10+(x[3]-'0');
                else if(i==1)
                    next.num=j*100+(x[0]-'0')*1000+(x[2]-'0')*10+(x[3]-'0');
                else if(i==2)
                    next.num=j*10+(x[0]-'0')*1000+(x[1]-'0')*100+(x[3]-'0');
                else if(i==3)
                    next.num=j+(x[1]-'0')*100+(x[2]-'0')*10+(x[0]-'0')*1000;
                if(isprime[next.num]&&!vis[next.num])//这个数是素数且没被标记过
                {
                    vis[next.num]=1;
                    next.money=now.money+1;
                    q.push(next);
                }
            }
        }
    }
    if(f==0)
    {
        cout<<"Impossible"<<endl;
        return;
    }
}
int main()
{
    eratos(10005);//10005以内的素数表
    cin>>T;
    while(T--)
    {
        ME0(vis);
        cin>>n>>m;
        bfs();
    }
}