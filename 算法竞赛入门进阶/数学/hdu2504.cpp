#include <cstdio>

int gcd(int m, int n)
{
    while(m>0)
    {
        int c = n % m;
        n = m;
        m = c;
    }
    return n;
}
 
int main()
{
    int n, a, b, c;
 
    scanf("%d", &n);
    while(n--) {
        scanf("%d%d", &a, &b);
        
        c = b + b;
        while(gcd(a, c) != b)
            c += b;
 
        printf("%d\n", c);
    }
 
    return 0;
}