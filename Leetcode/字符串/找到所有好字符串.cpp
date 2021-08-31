#define mst(x, a) memset(x, a, sizeof(x))

typedef long long ll;
const ll MOD = 1e9+7;

ll dp[510][51][2];

class Solution {
public:
    int findGoodStrings(int n, string s1, string s2, string evil) {
        build(evil);
        // --s1
        bool flag = false;
        for (int i = n - 1; i >= 0; i--) {
            if (s1[i] > 'a') {
                s1[i]--;
                flag = true;
                break;
            } else {
                s1[i] = 'z';
            }
        }

        if (flag) {
            return (helper(n, s2, evil) - helper(n, s1, evil) + MOD) % MOD;
        } else {
            return helper(n, s2, evil);
        }
    }
    
    int helper(int n, const string& s, const string& evil) {
        // printf("%s\n", s.c_str());
        mst(dp, 0);
        dp[0][0][1] = 1;
        for (int i = 0; i < n; i++) {
            for (int state = 0; state < evil.size(); state++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    int ns = getNextState(state, c, evil);
                    dp[i+1][ns][0] = (dp[i+1][ns][0] + dp[i][state][0]) % MOD;
                }
                for (char c = 'a'; c < s[i]; c++) {
                    int ns = getNextState(state, c, evil);
                    dp[i+1][ns][0] = (dp[i+1][ns][0] + dp[i][state][1]) % MOD;
                }
                int ns = getNextState(state, s[i], evil);
                dp[i+1][ns][1] = (dp[i+1][ns][1] + dp[i][state][1]) % MOD;
            }
        }
    
        int ans = 0;
        for (int i = 0; i < evil.size(); i++) {
            ans = (ans + dp[n][i][0]) % MOD;
            ans = (ans + dp[n][i][1]) % MOD;
        }
        return ans;
    }
        
    int getNextState(int state, char c, const string& evil) {
        int j = state;
        while (~j && evil[j] != c) j = next[j];
        return j + 1;
    }
    
    vector<int> next;
 
    // 求 next 数组
    void build(const string &pattern){
        int n = pattern.length();
        next.resize(n + 1);
        for (int i = 0, j = next[0] = -1; i < n; next[++i] = ++j){
            while(~j && pattern[j] != pattern[i]) j = next[j];
        }
    }
};
