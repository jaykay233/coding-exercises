#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define rank Rank
using namespace std;

const int MAXN = 2e5 + 10;
//后缀数组模版题
char str[MAXN];
int SA[MAXN], rank[MAXN], height[MAXN], sum[MAXN], tp[MAXN];
//rank[i] 第i个后缀的排名, SA[i] 排名为i的后缀的位置, Height[i] 排名为i的后缀与排名为(i-1)的后缀的LCP
//sum[i] 基数排序辅助数组, 存储小于i的元素有多少个, tp[i] rank的辅助数组(按第二关键字排序的结果),与SA意义一样

bool cmp(int *f, int x, int y, int w){
    return f[x] == f[y] && f[x + w] == f[y + w];
}

void get_SA(char *s, int n, int m){
    //先预处理长度为1的情况
    for(int i = 0; i < m; i++) sum[i] = 0;//清0
    for(int i = 0; i < n; i++) sum[rank[i] = s[i]]++;//统计每个字符出现的次数
    for(int i = 1; i < m; i++) sum[i] += sum[i - 1];//sum[i]为小于等于i的元素的数目
    for(int i = n - 1; i >= 0; i--) SA[--sum[rank[i]]] = i;//下标从0开始,所以先自减
    //SA[i]存储排名第i的后缀下标,SA[--sum[rank[i]]] = i 即下标为i的后缀排名为--sum[rank[i]],这很显然
    for(int len = 1; len <= n; len <<= 1){
        int p = 0;
        //直接用SA数组对第二关键字排序
        for(int i = n - len; i < n; i++) tp[p++] = i;//后面i个数没有第二关键字,即第二关键字为空,所以最小
        for(int i = 0; i < n; i++){
            if(SA[i] >= len) tp[p++] = SA[i] - len;
        }
        //tp[i]存储按第二关键字排序第i的下标
        //对第二关键字排序的结果再按第一关键字排序,和长度为1的情况类似
        for(int i = 0; i < m; i++) sum[i] = 0;
        for(int i = 0; i < n; i++) sum[rank[tp[i]]]++;
        for(int i = 1; i < m; i++) sum[i] += sum[i - 1];
        for(int i = n - 1; i >= 0; i--) SA[--sum[rank[tp[i]]]] = tp[i];
        //根据SA和rank数组重新计算rank数组
        swap(rank, tp);//交换后tp指向旧的rank数组
        p = 1;
        rank[SA[0]] = 0;
        for(int i = 1; i < n; i++){
            rank[SA[i]] = cmp(tp, SA[i - 1], SA[i], len) ? p - 1 : p++;//注意判定rank[i]和rank[i-1]是否相等
        }
        if(p >= n) break;
        m = p;//下次基数排序的最大值
    }
    //求height
    int k = 0;
    n--;
    for(int i = 0; i <= n; i++) rank[SA[i]] = i;
    for(int i = 0; i < n; i++){
        if(k) k--;
        int j = SA[rank[i] - 1];
        while(s[i + k] == s[j + k]) k++;
        height[rank[i]] = k;
    }
}

int main(void){
    char str[MAXN];
    while(~scanf("%s", str)){
        int len = strlen(str);
        str[len] = '0';
        scanf("%s", str + len + 1);
        int n = strlen(str);
        str[n] = 0; //末尾添加一个0
        get_SA(str, n + 1, 'z' + 1);
        int sol = 0;
        for(int i = 1; i < n; i++){
            if(SA[i] > len && SA[i - 1] < len) sol = max(sol, height[i]);
            if(SA[i] < len && SA[i - 1] > len) sol = max(sol, height[i]);
        }
        printf("%d\n", sol);
    }
    return 0;
}