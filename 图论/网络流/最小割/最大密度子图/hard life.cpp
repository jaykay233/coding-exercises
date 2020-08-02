#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <cstdio>
#include <algorithm>
using namespace std;
 
#define MAX_V 100 + 16
const double inf = 0x3fffffff;
const double eps = 1e-8;
int s, t, sum, degree[MAX_V], n, m;
bool visited[MAX_V];
typedef double cap_type;
 
// 邻接表用于表示边的结构体（终点、容量、反向边）
struct edge
{
	int to, rev;
	cap_type cap;
	edge(int to, cap_type cap, int rev) :to(to), cap(cap), rev(rev){}
};
 
// 边（起点，终点）
struct node
{
	int x, y;
}P[1024];
 
vector<edge> G[MAX_V];   // 图的邻接表表示
int level[MAX_V];      // 顶点到源点的距离标号
int iter[MAX_V];       // 当前弧，在其之前的边已经没有用了
 
// 向图中加入一条从from到to的容量为cap的边
void add_edge(int from, int to, cap_type cap)
{
	G[from].push_back(edge(to, cap, G[to].size()));
	G[to].push_back(edge(from, 0, G[from].size() - 1));
}
 
// 通过BFS计算从源点出发的距离标号
void bfs(int s)
{
	memset(level, -1, sizeof(level));
	queue<int> que;
	level[s] = 0;
	que.push(s);
	while (!que.empty())
	{
		int v = que.front(); que.pop();
		for (int i = 0; i < G[v].size(); ++i)
		{
			edge& e = G[v][i];
			if (e.cap > eps && level[e.to] < 0)
			{
				level[e.to] = level[v] + 1;
				que.push(e.to);
			}
		}
	}
}
 
// 通过DFS寻找增广路
cap_type dfs(int v, int t, cap_type f)
{
	if (v == t)
	{
		return f;
	}
	for (int& i = iter[v]; i < G[v].size(); ++i)
	{
		edge& e = G[v][i];
		if (e.cap > 0 && level[v] < level[e.to])
		{
			cap_type d = dfs(e.to, t, min(f, e.cap));
			if (d > eps)
			{
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
 
	return 0;
}
 
// 求解从s到t的最大流
cap_type max_flow(int s, int t)
{
	cap_type flow = 0;
	for (;;)
	{
		bfs(s);
		if (level[t] < 0)
		{
			return flow;
		}
		memset(iter, 0, sizeof(iter));
		cap_type f;
		while ((f = dfs(s, t, inf)) > eps)
		{
			flow += f;
		}
	}
}
 
void construct_graph(double g)
{
	for (int i = 0; i < MAX_V; ++i)
	{
		G[i].clear();
	}
	for (int i = 1; i <= n; i++)
	{
		add_edge(s, i, m);
		add_edge(i, t, m + 2 * g - degree[i]);
	}
	for (int i = 0; i < m; i++)
	{
		add_edge(P[i].x, P[i].y, 1.0);
		add_edge(P[i].y, P[i].x, 1.0);
	}
}
 
// 遍历
void dfs_travel(int v)
{
	++sum;
	visited[v] = true;
	vector<edge> gv = G[v];
	for (vector<edge>::iterator it = gv.begin(); it != gv.end(); ++it)
	{
		const edge &e = *it;
		if (e.cap > eps && !visited[e.to])
		{
			dfs_travel(e.to);
		}
	}
}
 
///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	if (m == 0)
	{
		printf("1\n1\n");
	}
	else
	{
		s = 0, t = n + 1;
		for (int i = 0; i < m; ++i)
		{
			scanf("%d%d", &P[i].x, &P[i].y);
			degree[P[i].x]++;
			degree[P[i].y]++;
		}
		// 二分求解分数规划
		double lb = 0, ub = m, mid, hg;
		const double precision = 1.0 / n / n;
		while (ub - lb >= precision)		//	误差的精度不超过1 / (n * n)
		{
			mid = (lb + ub) / 2;
			construct_graph(mid);
			hg = (n * m - max_flow(s, t)) / 2;
			(hg > eps ? lb : ub) = mid;
		}
		construct_graph(lb);				//	mid不一定满足h(mid) > eps,但是lb一定满足
		max_flow(s, t);
		sum = 0;
		dfs_travel(0);
		printf("%d\n", sum - 1);
		for (int i = 1; i <= n; ++i)
		{
			if (visited[i] == true)
			{
				printf("%d\n", i);
			}
		}
	}
 
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif
	return 0;
}