#include <bits/stdc++.h>
using namespace std;
const int N = 10100;
struct Node{
    int id;
    int cost;
};

vector<Node> tree[N];
int dp[N][3];
int n;

void init_read(){
    for(int i=1;i<=n;i++)
        tree[i].clear();
    memset(dp,0,sizeof dp);
    for(int i=2;i<=n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        Node tmp;
        tmp.cost = y;
        tmp.id = x;
        tree[x].push_back(tmp);
    }
}

void dfs1(int father){
    int one = 0,two = 0;
    for(int i=0;i<tree[father].size();i++){
        Node child = tree[father][i];
        dfs1(child.id);
        int cost = dp[child.id][0] + child.cost;
        if(cost>=one){
            two = one;
            one = cost;
        }
        if(cost>two && cost<one)
            two = cost;
    }
    dp[father][0] = one;
    dp[father][1] = two;
}


void dfs2(int father){
    for(int i=0;i<tree[father].size();i++){
        Node child = tree[father][i];
        if(dp[child.id][0] + cost == dp[father.id][0])
            dp[child.id][2] = max(dp[father][2],dp[father][1]) + child.cost;
        else
            dp[child.id][2] = max(dp[father][2],dp[father][0]) + child.cost;
        dfs2(child.id);
    }
}

int main(){
    while(~scanf("%d",&n)){
        init_read();
        dfs1(1);
        dp[1][2] = 0;
        dfs2(1);
        for(int i=1;i<=n;i++)
            printf("%d\n",max(dp[i][0],dp[i][2]));
    }
    return 0;
}