class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(),stones.end());
        int n = stones.size();
        int mx = stones[n-1] - stones[0] + 1 - n;
        mx -= min(stones[n-1]-stones[n-2] - 1, stones[1]-stones[0] -1);
        int mi = mx;
        int i=0;
        int j=0;
        for(i=0;i<n;i++){
            while(j+1<n && stones[j+1]-stones[i]+1<=n)
                j++;
            int cost =n - (j-i+1);
            if(j-i+1==n-1 && stones[j] - stones[i] + 1 == n-1)
                cost = 2;
            mi = min(mi,cost);
        }
        return vector<int>{mi,mx};
    }
};