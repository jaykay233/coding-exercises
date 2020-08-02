#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <queue>
using namespace std;
#define R register
#define W while
#define gc getchar()
#define IN inline
#define MX 1100005
struct Packet
{
    int add, delet, no, yes, cost;
}addons[1001];
queue <int> q;
int dist[MX];
bool inq[MX];
char s1[205], s2[205];
int main()
{
    int err, num;
    scanf("%d%d", &err, &num);
    for (R int i = 1; i <= num; ++i)
    {
        scanf("%d", &addons[i].cost);
        scanf("%s%s", s1, s2);
        for (R int j = 0; j < err; ++j)
        {
            if (s1[j] == '+') addons[i].yes ^= (1 << (err - j - 1));
            if (s1[j] == '-') addons[i].no  ^= (1 << (err - j - 1));
            if (s2[j] == '+') addons[i].add ^= (1 << (err - j - 1));
            if (s2[j] == '-') addons[i].delet ^= (1 << (err - j - 1));
        }
    }
    memset(dist, 63, sizeof(dist));
    q.push((1 << err) - 1);
    dist[(1 << err) - 1] = 0;
    inq[(1 << err) - 1] = true;
    R int now, nex;
    W (!q.empty())
    {
        now = q.front();
        q.pop();
        for (R int i = 1; i <= num; ++i)
        {
            if(!(now & addons[i].no) && !((now & addons[i].yes) ^ addons[i].yes))
            {
                nex = now | addons[i].add;
                nex = (nex | addons[i].delet) ; 
                nex = nex ^ addons[i].delet;
                if (dist[nex] > dist[now] + addons[i].cost)
                {
                    if (!inq[nex])
                    {
                        inq[nex] = true;
                        q.push(nex);
                    }
                    dist[nex] = dist[now] + addons[i].cost;
                }
            }
        }
        inq[now] = false;
    }
    if (dist[0] > 9999999) dist[0] = 0;
    printf("%d", dist[0]);
    return 0;
}