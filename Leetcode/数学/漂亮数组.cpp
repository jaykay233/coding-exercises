class Solution {
public:
    map<int,vector<int>> memo;
    vector<int> beautifulArray(int n) {
        return f(n);
    }

    vector<int> f(int N){
        if(memo.count(N))
            return memo[N];
        vector<int> ans(N);
        if(N==1)
            ans[0] = 1;
        else{
            int t = 0;
            for(int x:f((N+1)/2))
                ans[t++] = 2*x-1;
            for(int x:f(N/2))
                ans[t++] = 2*x;
        }
        memo[N] = ans;
        return ans;
    }
};