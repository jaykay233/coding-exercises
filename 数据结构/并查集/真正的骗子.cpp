#include <bits/stdc++.h>
using namespace std;
const int maxm = 700;
int bagcnt[maxm][2];
vector<int> bagele[maxm][2];
int bgcnt;
int dp[maxm][maxm], pre[maxm][maxm];
int fa[maxm], val[maxm], fb[maxm];
int n, p1, p2, xn;
vector<int> anss;

void init(){
    xn = p1 + p2;
    bgcnt = 0;
    for(int i = 0; i <= xn; i++) {
        fa[i] = i;
        bagele[i][0].clear();
        bagele[i][1].clear();
    }
    memset(val, 0, sizeof(val));
    memset(fb, 0, sizeof(fb));
    memset(bagcnt, 0, sizeof(bagcnt));
    memset(dp, 0, sizeof(dp));
    memset(pre, 0, sizeof(pre));
}
int find(int x){
    if(x ==fa[x]) return x;
    int tmp = find(fa[x]);
    val[x] += val[fa[x]];
    val[x] %= 2;
    return fa[x] = tmp;
}

int main(){
    while(scanf("%d %d %d", &n, &p1, &p2) && !(n == 0 && p1 == 0 && p2 == 0)){
        init();
        for(int i = 1; i <= n; i++){
            char str[5];
            int a, b;
            scanf("%d %d %s", &a, &b, str);
            int tmp = str[0] == 'y'? 0: 1;
            int rb = find(b), ra = find(a);
            if(ra != rb){
                fa[ra] = rb;
                val[ra] = (val[b] - val[a] + tmp + 2) % 2;
            }
        }
        if(p1 == p2){
            puts("no");
            continue;
        }  

        for(int i = 1;i<=xn;i++){
            int ri = find(i);
            if(fb[ri]==0) fb[ri] = ++bgcnt;
            bagcnt[fb[ri]][val[i]]++;
            bagele[fb[ri]][val[i]].push_back(i);
        }


        dp[0][0] = 1;
        for(int i = 1;i<=bgcnt;i++){
            for(int j =0;j<=p1;j++){
                if(j>=bagcnt[i][0] && dp[i-1][j-bagcnt[i][0]]){
                    dp[i][j] += dp[i-1][j-bagcnt[i][0]];
                    pre[i][j] = j - bagcnt[i][0];
                }

                if(j>=bagcnt[i][1] && dp[i-1][j-bagcnt[i][1]]){
                    dp[i][j] += dp[i-1][j-bagcnt[i][1]];
                    pre[i][j] = j-bagcnt[i][1];
                }
            }
        }
        if(dp[bgcnt][p1]!=1){
            puts("no");
            continue;
        }

        anss.clear();
        int tmp = p1,j = p1;
        for(int i = bgcnt;i;i--){
            int tmx = tmp - pre[i][j];
            if(bagcnt[i][0]==tmx){
                for(int t:bagele[i][0]) anss.push_back(t);
            }else{
                for(int t:bagele[i][1]) anss.push_back(t);
            }
            tmp = pre[i][j];
            j = pre[i][j];
        }
        sort(anss.begin(),anss.end());
        for(int i =0;i<anss.size();i++){
            printf("%d\n",anss[i]);
        }
        puts("end");
    }
    return 0;
}