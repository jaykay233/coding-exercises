//nim game，裸题 + 特殊情况判定
#include <bits/stdc++.h>
#define INF 1000000000
#define EPS 1e-6
using namespace std;

int t;
int n;
int a[50];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        bool flag = 0;
        int ans = 0;

        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            ans ^= a[i];
            if (a[i] != 1)
                flag = 1;
        }

        if (flag)
        {
            if (ans == 0)
                printf("Brother\n");
            else
                printf("John\n");
        }
        else
        {
            if (n % 2 == 0)
                printf("John\n");
            else
                printf("Brother\n");
        }
    }
    return 0;
}