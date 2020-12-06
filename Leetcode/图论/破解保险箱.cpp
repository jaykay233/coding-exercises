class Solution {
public:
    bool vis[10010];
    string res = "0";
    string crackSafe(int n, int k) {
        string st = "";
        for (int i = 0; i < n; i++) st += '0';
        memset(vis, false, sizeof(vis));
        dfs(k, st);
        return res + st.substr(1);
    }

    void dfs(int k,string s){
        int num = stoi(s);
        vis[num] = true;
        for (int i = 0; i < k; i++) {
            char c = '0' + i;
            string s0 = s + c;
            string s1 = s0.substr(1);
            if (!vis[stoi(s1)]) {
                dfs(k, s1);
                res += c;
            }
        }
    }
};