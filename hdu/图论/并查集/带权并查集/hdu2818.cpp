#include<iostream>
#include<stdio.h>
using namespace std;
const int MAX=100000;
 
int sum[MAX+10];
int under[MAX+10];
int pre [MAX];
 
void init(){
 
for(int i=0;i<=MAX;i++)
{
    pre[i]=i;
    sum[i]=1;
    under[i]=0;
}
}
 
int find(int x)
{
	if(pre[x]!=x){
		
		int temp=find(pre[x]);
		under[x]+=under[pre[x]];
		pre[x]=temp;
		return pre[x];
	}
        else return x;
}
 
void join(int x,int y)
{
    int a=find(x);
    int b=find(y);
    if(a!=b)
    {
    	under[a]=sum[b];
    	sum[b]+=sum[a];
        pre[a]=b;
       
    }
    else return;
}
 
int main()
{
    int n,x,y;
    char cmd;
    scanf("%d",&n);
    init();
    for(int i=1;i<=n;i++)
    {
        getchar();
        scanf("%c",&cmd);
        if(cmd=='M')
        {
            scanf("%d%d",&x,&y);
            join(x,y);
        }
        else
        {
            scanf("%d",&x);
            find(x);
            printf("%d\n",under[x]);
        }
    }
}