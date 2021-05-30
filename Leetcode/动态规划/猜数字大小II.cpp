class Solution {
public:
    unordered_map<string,int> m;
    vector<vector<int>> visit;
    int getMoneyAmount(int n) {
        visit = vector<vector<int>>(n+1,vector<int>(n+1,-1));
        return dp(1,n);
    }

    int dp(int i,int j){
        if(i>=j) return 0;
        if(visit[i][j]!=-1) return visit[i][j];
        int cost = INT_MAX;
        for(int x=i;x<j;x++){
            int l = dp(i,x-1);
            int r = dp(x+1,j);
            cost = min(cost, x + max(l,r));
        }
        return visit[i][j] = cost;
    }
};