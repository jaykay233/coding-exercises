#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10555;
const int MAXM = 21111;

struct Edge
{
    int to,next;
};
Edge edge[MAXM];
int head[MAXN],Stack[MAXN],Low[MAXN],Dfn[MAXN],f[MAXN],Count[MAXN];
vector<int> Belong[MAXN];
int tot,top,Index,block,cc;

void init()
{
    memset(head,-1,sizeof(head));
    memset(f,-1,sizeof(f));
    tot = 0;
}

void addedge(int u, int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}

int getf(int x)
{
    if(f[x] == -1)
        return x;
    return f[x]=getf(f[x]);
}

void mmerge(int u, int v)
{
    u = getf(u);
    v = getf(v);
    if(u != v)
        f[v] = u;
}

void Tarjan(int u, int fa)
{
    Low[u] = Dfn[u] = ++Index;
    Stack[top++] = u;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if(!Dfn[v])
        {
            Tarjan(v,u);
            Low[u] = min(Low[u],Low[v]);
            if(Low[v] >= Dfn[u])
            {
                block++;
                cc = 0;
                int vn;
                do
                {
                    vn = Stack[--top];
                    ++cc;
                    Belong[vn].push_back(block);
                }while(vn != v);
                Belong[u].push_back(block);
                Count[block] = cc+1;
            }
        }
        else if(v != fa)
            Low[u] = min(Low[u],Dfn[v]);
    }
}

void solve(int n)
{
    memset(Low,0,sizeof(Low));
    memset(Dfn,0,sizeof(Dfn));
    memset(Count,0,sizeof(Count));
    Index = top = block = 0;
    for(int i = 1; i <= n; ++i)
        Belong[i].clear();

    for(int i = 1; i <= n; ++i)
        if(!Dfn[i])
            Tarjan(i,-1);
}

int main()
{
    int n,m,q,u,v,time = 0;;
    while(scanf("%d %d %d",&n,&m,&q) && n+m+q)
    {
        init();
        for(int i = 0; i < m; ++i)
        {
            scanf("%d %d",&u,&v);
            u++,v++;
            mmerge(u,v);
            addedge(u,v);
            addedge(v,u);
        }
        solve(n);
        printf("Case %d:\n",++time);
        while(q--)
        {
            scanf("%d %d",&u,&v);
            u++,v++;
            if(getf(u) != getf(v))
            {
                printf("zero\n");
                continue;
            }
            bool flag = false;
            int res = -1;
            for(int i = 0; i < Belong[u].size(); ++i)
            {
                for(int j = 0; j < Belong[v].size(); ++j)
                {
                    if(Belong[u][i] == Belong[v][j])
                    {
                        flag = true;
                        res = Belong[u][i];
                        break;
                    }
                }
                if(flag) break;
            }

            if(res != -1 && Count[res] > 2)
                printf("two or more\n");
            else
                printf("one\n");
        }
    }
    return 0;
}
