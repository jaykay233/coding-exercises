#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n,m;

void mul(int c[], int a[], int b[])
{
    static int temp[N];
    memset(temp, 0, sizeof temp);

    for (int i = 0; i < m; i ++ )
        for (int j = 0; j < m; j ++ )
            if (i + j < m)
                temp[i + j] += a[i] * b[j];
    for (int i = 0, t = 0; i < m; i ++ )
    {
        t += temp[i];
        temp[i] = t % 10;
        t /= 10;
    }
    memcpy(c, temp, sizeof temp);
}

void mul(int c[], int a[], int b)
{
    for (int i = 0, t = 0; i < m; i ++ )
    {
        t += a[i] * b;
        c[i] = t % 10;
        t /= 10;
    }
}

int nums[N];
int power[N];

int main()
{
    string str;
    cin >> str >> m;
    for (int i = 0, j = str.size() - 1; j >= 0; j --, i ++ ) nums[i] = str[j] - '0';
    memcpy(power, nums, sizeof nums);

    int per[N] = {1};
    int p1[N], pn[N];    

    for (int k = 1; k <= m; k ++ )
    {
        memcpy(pn, nums, sizeof nums);
        memset(p1, 0, sizeof p1);
        p1[0] = 1;

        int r = 0;
        while (r <= 10)
        {
            mul(pn, pn, power);
            mul(p1, p1, power);
            r ++ ;
            if (pn[k - 1] == nums[k - 1]) break;
        }
        memcpy(power, p1, sizeof p1);

        if (r > 10)
        {
            memset(per, 0, sizeof per);
            per[0] = -1;
            break;
        }

        mul(per, per, r);
    }

    int k = m;
    while (!per[k]) k -- ;

    while (k >= 0) cout << per[k -- ];

    return 0;
}



