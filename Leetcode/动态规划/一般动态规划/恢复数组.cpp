using LL = long long;

class Solution {
private:
    static constexpr int mod = 1000000007;

public:
    int numberOfArrays(string s, int k) {
        int n = s.size();
        // 为了便于代码编写，我们使用 64 位整数类型
        LL kll = k;
        vector<int> f(n + 1, 0);
        // 递推的边界条件
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            LL num = 0, base = 1;
            // 倒序枚举 j，最多只需要枚举 10 个
            for (int j = i - 1; j >= 0 && i - j <= 10; --j) {
                // 在高位添加当前的数字，得到第 j+1 到 i 个数字组成的数
                // 注意 s 的下标是从 0 开始的
                num += (s[j] - '0') * base;
                if (num > kll) {
                    break;
                }
                // 判断是否有前导 0
                if (s[j] != '0') {
                    f[i] += f[j];
                    f[i] %= mod;
                }
                base *= 10;
            }
        }
        return f[n];
    }
};