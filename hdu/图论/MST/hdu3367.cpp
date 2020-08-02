#include <bits/stdc++.h> 
using namespace std;
 
typedef long long LL;
 
const int N = 10005;
const int INF = 0x3f3f3f3f;
 
int pre[N], n, ednum, sum;
bool circle[N];
 
struct node
{
    int u, v, w;
}edge[100005];
 
bool cmp(node x, node y)
{
    if(x.w>y.w) return true;
    else return false;
}
 
int Find(int x)
{
    int r = x;
    while(r != pre[r])
        r = pre[r];
    int i = x, j;
    while(pre[i] != r)
    {
        j = pre[i];
        pre[i] = r;
        i = j;
    }
    return r;
}
 
void Union(int p1, int p2, int w)
{
    int x = Find(p1);
    int y = Find(p2);
    if(x != y)//不在同一棵树上
    {
        if(circle[x]==false && circle[y]==false)//两棵树都没有环
        {
            pre[x] = y;
            sum+=w;
        }
        else if((circle[x]==true&&circle[y]==false) || (circle[x]==false&&circle[y]==true))//一棵树有环
        {
            pre[x] = y;
            sum+=w;
            circle[y] = true;
        }
    }
    else//在同一棵树上
    {
        if(circle[x]==false && circle[y]==false)//两棵树都没有环
        {
            pre[x] = y;
            sum+=w;
            circle[y] = true;
        }
    }
}
 
void kruskal()
{
    for(int i = 0; i < n; i++)//起点坐标可以是0
    {
        pre[i] = i;
    }
    memset(circle, false, sizeof(circle));
    sort(edge+1, edge+1+ednum, cmp);
    for(int i = 1; i <= ednum; i++)
    {
        Union(edge[i].u, edge[i].v, edge[i].w);
    }
}
 
 
int main()
{
  //  freopen("in.txt", "r", stdin);
    int u, v, w;
    while(~scanf("%d%d", &n, &ednum))
    {
        if(n==0 && ednum==0) break;
        sum = 0;
        for(int i = 1; i <= ednum; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            edge[i] = (struct node){u, v, w};
        }
       // prim();
        kruskal();
        printf("%d\n", sum);
    }
    return 0;
}