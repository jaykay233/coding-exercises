#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
struct Ticket
{
    int time, price;
}q[N];
bool st[N];

int main()
{
    scanf("%d", &n);

    int res = 0;
    for (int i = 0, l = 0, r = 0; i < n; i ++ )
    {
        int type, price, time;
        scanf("%d%d%d", &type, &price, &time);
        if (type == 0)
        {
            q[r ++ ] = {time, price};
            res += price;
        }
        else
        {
            while (l < r && time - q[l].time > 45) l ++ ;

            bool success = false;
            for (int j = l; j < r; j ++ )
                if (!st[j] && q[j].price >= price)
                {
                    st[j] = true;
                    success = true;
                    break;
                }
            if (!success) res += price;
        }
    }

    printf("%d\n", res);

    return 0;
}