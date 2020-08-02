
#include<bits/stdc++.h>
using namespace std;
#define N 20005
int pre[N],r[N];
int n,q;
int k,num[N];
char ope[1000];
vector<int>que;
void init()
{
    for(int i=0;i<=n;i++) 
	{
		pre[i]=i;
		r[i]=0;	
	}
}
int find(int x)
{
    if(x!=pre[x])
    {
        int t=pre[x];
        pre[x]=find(pre[x]);
        r[x]^=r[t];
    }
    return pre[x];
}
bool Union(int a,int b,int c)
{
    int ra=find(a),rb=find(b);
    if(ra==rb)//冲突 
    {
        if((r[a]^r[b])!=c) 
			return false;
        else 
			return true;
    }
    if(ra==n) 
		swap(ra,rb);  
    pre[ra]=rb;
    r[ra]=r[a]^r[b]^c;
    return true;
}
int Query()
{
    bool vis[N];
	memset(vis,false,sizeof(vis));
    int ans=0;
    for(int i=0;i<k;i++)
    {
        if(vis[i])
			continue;
        int cnt=0;
        int root=find(num[i]);//根 
        for(int j=i;j<k;j++)
        {
            if(!vis[j]&&find(num[j])==root)//j没有访问过 且在一个集合 
            {
                cnt++;
                vis[j]=true;
                ans^=r[num[j]];
            }
        }
        if(root!=n&&cnt&1) return -1;
    }
    return ans;
}
int main()
{
    int t=0;
    while(scanf("%d%d",&n,&q),n)
    {
        printf("Case %d:\n",++t);
        init();
        bool error=false;
        int fact=0;
        while(q--)
        {
            scanf("%s",ope);
            if(ope[0]=='I')
            {
                getchar();
				gets(ope);
				fact++;
                int space=0,u,v,w;
                for(int i=0;i<strlen(ope);i++) //检查有几个空格 
					space=space+(ope[i]==' '); 
                if(space==1) //一个空格表示2个输入
				{
					sscanf(ope,"%d%d",&u,&w);
					v=n;
				}
                else 
					sscanf(ope,"%d%d%d",&u,&v,&w);
                if(error) 
					continue;
                if(!Union(u,v,w))//冲突 
				{
					printf("The first %d facts are conflicting.\n",fact);
					error=true;
				}
            }
            else
            {
                scanf("%d",&k);
                for(int i=0;i<k;i++)
					scanf("%d",&num[i]);
                if(error) 
					continue;
                int ans=Query();
                if(ans==-1) 
					puts("I don't know.");
                else 
					printf("%d\n",ans);
            }
        }
        puts("");
    }
    return 0;
}