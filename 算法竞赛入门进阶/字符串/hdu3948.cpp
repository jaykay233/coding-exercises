//https://blog.csdn.net/luyuyingyingying/article/details/107287119?utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7Edefault-8.no_search_link&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7Edefault-8.no_search_link
#include <bits/stdc++.h>
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

void init_sa(){
    mt(sa_height,0);
    mt(sa_cnt,0);
    mt(sa_rk,0);
    mt(sa_t1,0);
    mt(sa_t2,0);
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

int askRMQ(int a,int b){
    int t;
    t = mm[b-a+1];
    b -= (1<<t)-1;
    a = best[t][a];
    b = best[t][b];
    return RMQ[a] < RMQ[b] ? a : b;
}

int lcp(int a,int b){
    a = sa_rk[a];
    b = sa_rk[b];
    if(a>b) swap(a,b);
    return sa_height[askRMQ(a+1,b)];
}

char str[mc];
int r[mc];
int sa[mc];

int main(){
    int t;
    cin>>t;
    for(int j =0;j<t;j++){
        init_sa();
        scanf("%s",str);
        int len = strlen(str);
        int n = 2 * len + 1;
        for(int i =0;i<len; i++)
            r[i] = str[i];
        r[len] = '$';
        for(int i =0 ;i<len;i++)
            r[len + i + 1] = str[len-1-i];
        r[n] = 0;
        da(r,sa,sa_rk, sa_height,n,128);
        for(int i=1;i<=n;i++) RMQ[i] = sa_height[i];
        initRMQ(n);
        int ans =0, cnt1 =0,cnt2=0;
        int tmp;
        for(int i=1;i<=n;i++){
            cnt1 = min(cnt1, sa_height[i]);
            cnt2 = min(cnt2, sa_height[i]);
            if(sa[i] >= len) continue;
            tmp = lcp(sa[i],n - sa[i] - 1);
            if(tmp > cnt1) ans += tmp - cnt1, cnt1 = tmp;

            tmp = lcp(sa[i],n - sa[i]);
            if(tmp > cnt2) ans += tmp - cnt2, cnt2 = tmp;
        }
        printf("Case: %d: %d\n", j + 1, ans);
    }
    return 0;
}