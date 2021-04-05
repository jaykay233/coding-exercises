#include <iostream>

using namespace std;

#define LL long long

LL gcd(LL a, LL b)
{
    return b ? gcd(b, a%b) : a;
}

//find x, y that satisfied the equation ax+by=d, which minimize the {|x|+|y|}. ps:d = gcd(a,b).
void exgcd(LL a, LL b, LL &d, LL &x, LL &y)
{
    if (!b)
    {
        d = a, x = 1, y = 0;
    }
    else
    {
        exgcd(b, a %b, d, y, x);
        y -= x * (a / b);
    }
}
//1、先计算Gcd(a, b)，若n不能被Gcd(a, b)整除，则方程无整数解；否则，在方程两边同时除以Gcd(a, b)，得到新的不定方程a' * x + b' * y = n'，此时Gcd(a', b')=1;
//2、利用上面所说的欧几里德算法求出方程a' * x + b' * y = 1的一组整数解x0, y0，则n' * x0,n' * y0是方程a' * x + b' * y = n'的一组整数解；
//3、根据数论中的相关定理，可得方程a' * x + b' * y = n'的所有整数解为：
//x = n' * x0 + b' * t
//y = n' * y0 - a' * t
//(t为整数)
bool getans(LL a, LL b, LL c, LL &ans)// ax + by = c 最小整数解
{
    LL r = gcd(a, b), y0;
    if (c%r)//no solutions
    {
        return false;
    }

    a /= r, b /= r, c /= r;

    exgcd(a, b, r, ans, y0);//至此，上面的说明解决了

    LL t = c * ans / b;
    ans = c * ans - t * b;

    /*此时方程的所有解为：x = c*ans - b*t, x的最小的可能值是0
    令x = 0可求出当x最小时的t的取值，但由于x = 0是可能的最小取值，实际上可能x根本取不到0
    那么由计算机的取整除法可知：由 t = c*k1 / b算出的t
    代回x = c*ans - b*t中，求出的x可能会小于0，此时令t = t + 1，求出的x必大于0；
    如果代回后x仍是大于等于0的，那么不需要再做修正。*/

    if (ans < 0)
    {
        ans += b;
    }
    return true;
}


int main()
{
    LL x, y, m, n, L;
    while (cin >> x >> y >> m >> n >> L)
    {
        LL a = n - m, b = L, c = x - y;
        LL ans;
        bool flag = getans(a, b, c, ans);
        if (!flag)
        {
            cout << "Impossible" << endl;
            continue;
        }
        cout << ans << endl;
    }
}