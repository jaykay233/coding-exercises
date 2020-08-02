#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
#define maxn 11111
struct Tree
{
    int left,right,num,flag,len;
    bool lf,rf;
}T[4*maxn];
struct Line
{
    int x,y1,y2;
    bool flag;
}line[maxn];
int n,cnt,res,y[maxn],ans,num,len;
void add(int x,int y1,int y2,int yy,int flag)
{
    line[cnt].x=x;line[cnt].y1=y1;line[cnt].y2=y2;line[cnt].flag=flag;y[cnt++]=yy;
}
bool cmp(Line l1,Line l2)
{
    if(l1.x!=l2.x) return l1.x<l2.x;
    return l1.flag>l2.flag;
}
void build(int l,int r,int t)
{
    T[t].left=l;
    T[t].right=r;
    T[t].num=T[t].len=T[t].flag=T[t].lf=T[t].rf=0;
    if(l+1==r)return ;
    int mid=(l+r)>>1;
    build(l,mid,t<<1);
    build(mid,r,t<<1|1);
} 
void update_num(int t)
{
    if(T[t].flag) T[t].lf=T[t].rf=T[t].num=1;
    else if(T[t].left+1==T[t].right) T[t].lf=T[t].rf=T[t].num=0;
    else
    {
        T[t].lf=T[t<<1].lf;
        T[t].rf=T[t<<1|1].rf;
        T[t].num=T[t<<1].num+T[t<<1|1].num-T[t<<1].rf*T[t<<1|1].lf;
    }
}
void update_len(int t)
{
    if(T[t].flag) T[t].len=y[T[t].right]-y[T[t].left];
    else if(T[t].left+1==T[t].right) T[t].len=0;
    else T[t].len=T[2*t].len+T[2*t+1].len;
}
void update(int l,int r,int z,int t)
{
    if(y[T[t].left]==l&&y[T[t].right]==r) T[t].flag+=z;
    else if(T[t].left+1==T[t].right) return ;
    else
    {
        int mid=(T[t].left+T[t].right)>>1;
        if(r<=y[mid]) update(l,r,z,t<<1);
        else if(l>=y[mid]) update(l,r,z,t<<1|1);
        else
        {
            update(l,y[mid],z,t<<1);
            update(y[mid],r,z,t<<1|1);
        }
    }
    update_num(t);
    update_len(t);
}
int main()
{
    while(~scanf("%d",&n))
    {
        cnt=0;ans=0;len=num=0;
        int x1,x2,y1,y2;
        while(n--)
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            add(x1,y1,y2,y1,1);
            add(x2,y1,y2,y2,0); 
        }
        sort(line,line+cnt,cmp); 
        sort(y,y+cnt); 
        res=unique(y,y+cnt)-y;
        build(0,res-1,1);
        for(int i=0;i<cnt;i++)
        {
            if(line[i].flag) update(line[i].y1,line[i].y2,1,1); 
            else update(line[i].y1,line[i].y2,-1,1); 
            if(i) ans+=2*num*(line[i].x-line[i-1].x); 
            ans+=abs(T[1].len-len); 
            len=T[1].len;
            num=T[1].num; 
        }
        printf("%d\n",ans);
    } 
    return 0;
} 