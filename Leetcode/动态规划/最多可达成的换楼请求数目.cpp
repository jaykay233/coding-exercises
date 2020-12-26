class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {

        int res = 0;

        // 初始优化，统计入度和出度
        vector<int> indegrees(n, 0), outdegrees(n, 0);
        for(const vector<int>& e: requests)
            if(e[0] != e[1]) outdegrees[e[0]] ++, indegrees[e[1]] ++;
            else res ++; // 子环边直接算到解里

        vector<vector<int>> rv;
        for(const vector<int>& request: requests){
            int a = request[0], b = request[1];
            if(a == b || !indegrees[a] || !indegrees[b] || !outdegrees[a] || !outdegrees[b])
                continue;
            rv.push_back(request);
        }

        // rv 是优化后有可能被考虑的请求，下面的包里搜索和前面一样
        int r = rv.size(), t = 0;
        for(int i = 0; i < (1 << r); i ++)
            t = max(t, tryRequest(n, rv, i));
        return res + t;
    }

private:
    int tryRequest(int n, const vector<vector<int>>& requests, int state){

        vector<int> in(n, 0), out(n, 0);
        int index = 0, res = 0;
        while(state){
            if(state & 1){
                out[requests[index][0]] ++;
                in[requests[index][1]] ++;
                res ++;
            }

            state >>= 1, index ++;
        }

        if(in != out) return -1;
        return res;
    }
};
