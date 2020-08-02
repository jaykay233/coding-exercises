#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 1010;

int n, m, L, K, D;
PII row[N], col[N];
int q[N];

int main()
{
    cin >> n >> m >> K >> L >> D;

    for (int i = 1; i <= n; i ++ ) row[i].second = i;
    for (int i = 1; i <= m; i ++ ) col[i].second = i;

    while (D -- )
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (abs(x1 - x2) == 1) row[min(x1, x2)].first ++ ;
        else col[min(y1, y2)].first ++ ;
    }

    sort(row + 1, row + n + 1);
    sort(col + 1, col + m + 1);

    int cnt = 0;
    for (int i = n; i > n - K; i -- ) q[cnt ++ ] = row[i].second;
    sort(q, q + cnt);
    for (int i = 0; i < cnt; i ++ ) printf("%d ", q[i]);
    puts("");

    cnt = 0;
    for (int i = m; i > m - L; i -- ) q[cnt ++ ] = col[i].second;
    sort(q, q + cnt);
    for (int i = 0; i < cnt; i ++ ) printf("%d ", q[i]);
    puts("");

    return 0;
}

 