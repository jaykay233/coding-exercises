//不相同的子串个数
//https://blog.csdn.net/hjt_fathomless/article/details/52397218?utm_medium=distribute.pc_relevant.none-task-blog-2~default~baidujs_title~default-0.no_search_link&spm=1001.2101.3001.4242
#include <bits/stdc++.h>
#include <cstring>
#include <algorithm>
using namespace std;
#define rep(i,s,t) for(int i =(s);i<(t);i++)
#define per(i,t,s) for(int i=(t);i>=(s);i--)

const int INF = 1e9 + 9;
const int N = 20000 + 9;


int sa[N], t1[N], t2[N], c[N], rk[N], height[N];
void build_sa (int s[], int n, int m) {
    int i, k, p, *x = t1, *y = t2;
    for (i = 0; i < m; i++) c[i] = 0;
    for (i = 0; i < n; i++) c[x[i] = s[i]]++;
    for (i = 1; i < m; i++) c[i] += c[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
    for (k = 1; k <= n; k <<= 1) {
        p = 0;
        for (i = n - k; i < n; i++) y[p++] = i;
        for (i = 0; i < n; i++) if (sa[i] >= k) y[p++] = sa[i] - k;

        for (i = 0; i < m; i++) c[i] = 0;
        for (i = 0; i < n; i++) c[x[y[i]]]++;
        for (i = 1; i < m; i++) c[i] += c[i - 1];
        for (i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
        swap (x, y);
        p = 1;
        x[sa[0]] = 0;
        for (i = 1; i < n; i++)
            x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p ++;
        if (p >= n) break;
        m = p;
    }
}
void getHeight (int s[], int n) {
    int i, j, k = 0;
    for (i = 0; i <= n; i++) rk[sa[i]] = i;
    for (i = 0; i < n; i++) {
        if (k) k--;
        j = sa[rk[i] - 1];
        while (s[i + k] == s[j + k]) k++;
        height[rk[i]] = k;
    }
}

int s[N];
char str[N];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",str);
        int n = strlen(str);
        rep(i,0,n) s[i] = str[i];
        s[n] = 0;
        build_sa(s, n + 1, 128);
        getHeight(s,n);
        int ans = (n+1)*n/2;
        rep(i, 2, n+1) ans -= height[i];
        printf("%d\n", ans);
    }
}