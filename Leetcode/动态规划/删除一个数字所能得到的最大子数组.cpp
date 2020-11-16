class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int len = arr.size();
        vector<int> f(len);
        vector<int> g(len);
        f[0] = arr[0];
        g[0] = -200001;
        int res = max(f[0],g[0]);
        for(int i=1;i<len;i++){
            f[i] = max(f[i-1] + arr[i],arr[i]);
            g[i] = max(g[i-1] + arr[i],f[i-1]);
            res = max(res,max(f[i],g[i]));
        }
        return res;
    }
};