#include<bits/stdc++.h>

using namespace std;
#define mt(x, k) memset(x,k,sizeof(x))
const int mc = 200010;
int sa_t1[mc], sa_t2[mc], sa_cnt[mc];

bool cmp(const int *r, int a, int b, int l) {
    return r[a] == r[b] && r[a + l] == r[b + l];
}

void da(const int str[], int sa[], int rank[], int height[], int n, int m) {
    n++;
    int i, j, p, *x = sa_t1, *y = sa_t2;
    for (i = 0; i < m; i++)sa_cnt[i] = 0;
    for (i = 0; i < n; i++)sa_cnt[x[i] = str[i]]++;
    for (i = 1; i < m; i++)sa_cnt[i] += sa_cnt[i - 1];
    for (i = n - 1; i >= 0; i--)sa[--sa_cnt[x[i]]] = i;
    for (j = 1; j <= n; j <<= 1) {
        p = 0;
        for (i = n - j; i < n; i++)y[p++] = i;
        for (i = 0; i < n; i++)if (sa[i] >= j)y[p++] = sa[i] - j;
        for (i = 0; i < m; i++)sa_cnt[i] = 0;
        for (i = 0; i < n; i++)sa_cnt[x[y[i]]]++;
        for (i = 1; i < m; i++)sa_cnt[i] += sa_cnt[i - 1];
        for (i = n - 1; i >= 0; i--)sa[--sa_cnt[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for (i = 1; i < n; i++)
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
        if (p >= n)break;
        m = p;
    }
    int k = 0;
    n--;
    for (i = 0; i <= n; i++)rank[sa[i]] = i;
    for (i = 0; i < n; i++) {
        if (k)k--;
        j = sa[rank[i] - 1];
        while (str[i + k] == str[j + k])k++;
        height[rank[i]] = k;
    }
}

int sa_rk[mc], sa_height[mc];
int RMQ[mc];
int mm[mc];
int best[20][mc];

void init_sa() {
    mt(sa_height, 0);
    mt(sa_cnt, 0);
    mt(sa_rk, 0);
    mt(sa_t1, 0);
    mt(sa_t2, 0);
}

void initRMQ(int n) {
    mm[0] = -1;
    for (int i = 1; i <= n; i++)
        mm[i] = ((i & (i - 1)) == 0) ? mm[i - 1] + 1 : mm[i - 1];
    for (int i = 1; i <= n; i++)best[0][i] = i;
    for (int i = 1; i <= mm[n]; i++)
        for (int j = 1; j + (1 << i) - 1 <= n; j++) {
            int a = best[i - 1][j];
            int b = best[i - 1][j + (1 << (i - 1))];
            if (RMQ[a] < RMQ[b])best[i][j] = a;
            else best[i][j] = b;
        }
}

int askRMQ(int a, int b) {
    int t;
    t = mm[b - a + 1];
    b -= (1 << t) - 1;
    a = best[t][a];
    b = best[t][b];
    return RMQ[a] < RMQ[b] ? a : b;
}

//求两个后缀的最长公共前缀
int lcp(int a, int b) {
    a = sa_rk[a];
    b = sa_rk[b];
    if (a > b)swap(a, b);
    return sa_height[askRMQ(a + 1, b)];
}

char str[mc];//输入字符串的
int r[mc];//处理字符串的
int sa[mc];

int main() {
    int t;
    cin >> t;
    for (int j = 0; j < t; ++j) {
        init_sa();
        scanf("%s", str);
        int len = strlen(str);
        int n = 2 * len + 1;
        for (int i = 0; i < len; i++)
            r[i] = str[i];
        //将字符串反向存储在r数组中
        for (int i = 0; i < len; i++)
            r[len + 1 + i] = str[len - 1 - i];
        //用一个(字符串中不存在的)符号，来分隔开两个字符串
        r[len] = '$';
        //为了计算后缀数组，结尾要为0
        r[n] = 0;
        da(r, sa, sa_rk, sa_height, n, 128);//一步到位，后缀数组和高度数组都计算完了
        for (int i = 1; i <= n; i++) RMQ[i] = sa_height[i];
        initRMQ(n);
        int ans = 0, cnt1 = 0, cnt2 = 0;
        int tmp;
        for (int i = 1; i <= n; i++) {//注意n是两个字符串合并后的总长
            //下面这两行用于记录已经统计过的回文子串
            cnt1 = min(cnt1, sa_height[i]);//记录统计过的以sa[i]为中心的奇数回文串
            cnt2 = min(cnt2, sa_height[i]);//记录统计过的以sa[i]为中心的偶数回文串
            if (sa[i] >= len) continue;//避免重复统计
            tmp = lcp(sa[i], n - sa[i] - 1);//统计以sa[i]为中心的奇数回文子串数量
            if (tmp > cnt1) ans += tmp - cnt1, cnt1 = tmp;
            //上面这行表示
            //如果以sa[i]为中心的奇数回文子串数量，大于统计过的以sa[i]为中心的奇数回文串数量
            //那说明我们统计到了一些新的回文子串
            //ans += tmp - cnt1当前统计的回文子串数，减去统计过的，就是新统计的回文子串数
            //同时更新cnt1，表示我们统计到了更多的回文子串
            //下面统计偶数回文子串同理
            tmp = lcp(sa[i], n - sa[i]);//统计以sa[i]为中心的偶数回文子串数量
            if (tmp > cnt2) ans += tmp - cnt2, cnt2 = tmp;
        }
        printf("Case #%d: %d\n", j + 1, ans);
    }
    return 0;
}
