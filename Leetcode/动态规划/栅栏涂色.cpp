// 当前栅栏的涂色方案有两种
// 和前一个颜色相同，此时说明前一个的栅栏的颜色应与更前面一个栅栏的颜色不同，更前一个栅栏的涂色方法有 F(n - 2) 种，前一个栅栏的涂色方式有 (k - 1) 种，所以此时情况应为 F(n - 2) * (k - 1)
// 和前一个颜色不同，前一个栅栏的涂色方法有 F(n - 1) 种，当前栅栏的涂色方式有 (k - 1) 种，此时情况应为 F(n - 1) * (k - 1)
// 所以递推公式应为 F(n) = F(n - 2) * (k - 1) + F(n - 1) * (k - 1)


class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0 || k == 0) {
            return 0;
        }
        if (n == 1) {
            return k;
        }
        int pprev = k;
        int prev = k * k;
        int result = k * k;
        for (int i = 2; i < n; ++i) {
            result = prev * (k - 1) + pprev * (k - 1);
            pprev = prev;
            prev = result;
        }
        return result;
    }
};
