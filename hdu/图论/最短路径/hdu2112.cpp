#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <assert.h>
#include <time.h>
#define Max 160
typedef long long LL;
const int INF = 500000001;
const double EPS = 1e-9;
const double PI = acos(-1.0);
using namespace std;
int graph[Max][Max], s, e;
int val[Max], vis[Max];
void init()
{
    for(int i = 0; i < Max; i++)
    {
        for(int j = 0; j < Max; j++)
        {
            if(i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }
}
void dijkstra()
{
    for(int i = 0; i < Max; i++)
    {
        val[i] = graph[s][i];
        vis[i] = -1;
    }
    vis[s] = 1;
    int minn, v;
    for(int j = 1; j < Max; j++)
    {
        minn = INF;
        v = -1;
        for(int i = 0; i < Max; i++)
        {
            if(vis[i] == -1 && minn > val[i])
            {
                minn = val[i];
                v = i;
            }
        }
        if(v == -1)
        {
            break;
        }
        vis[v] = 1;
        for(int i = 0; i < Max; i++)
        {
            if(vis[i] == -1)
            {
                val[i] = min(val[i], val[v] + graph[v][i]);
            }
        }
    }
}
int main()
{
    #ifdef _1Test
        freopen("test0.in", "r", stdin);
        freopen("test0.out", "w", stdout);
        srand(time(NULL));
    #endif
    int N, cnt, dis;
    char ch[4][100];
    while(scanf("%d", &N), N != -1)
    {
        map<string, int> mm;
        cnt = 0;
        scanf("%s %s", ch[0], ch[1]);
        init();
        for(int i = 0; i < N; i++)
        {
            scanf("%s %s %d", ch[2], ch[3], &dis);
            if(mm.find(ch[2]) == mm.end())
            {
                mm[ch[2]] = cnt++;
            }
            if(mm.find(ch[3]) == mm.end())
            {
                mm[ch[3]] = cnt++;
            }
            int v1 = mm[ch[2]], v2 = mm[ch[3]];
            graph[v1][v2] = graph[v2][v1] = min(dis, graph[v1][v2]);
        }
        if(mm.find(ch[0]) == mm.end())
        {
            mm[ch[0]] = cnt++;
        }
        if(mm.find(ch[1]) == mm.end())
        {
            mm[ch[1]] = cnt++;
        }
        s = mm[ch[0]];
        e = mm[ch[1]];
        dijkstra();
        if(val[e] == INF)
            printf("-1\n");
        else
            printf("%d\n", val[e]);
    }
    return 0;
}