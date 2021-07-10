//https://leetcode-cn.com/problems/rotated-digits/solution/guan-fang-ti-jie-dong-tai-gui-hua-cjie-s-3y3j/
class Solution {
public:
    int rotatedDigits(int n) {
        string s = to_string(n);
        int K = s.size();
        vector<vector<vector<int>>> memo(K+1,vector<vector<int>>(2,vector<int>(2)));
        memo[K][0][1] = memo[K][1][1] = 1;
        for(int i = K - 1;i>=0;i--){
            for(int eqf=0;eqf<=1;eqf++){
                for(int invf = 0;invf <=1;invf++){
                    int ans =0 ;
                    for(char d = '0'; d<=(eqf==1?s[i]:'9');d++){
                        if(d=='3' || d=='4' || d=='7') continue;
                        bool invo = (d=='2' || d=='5' || d=='6' || d=='9');
                        ans += memo[i+1][d==s[i]?eqf:0][invo?1:invf];
                    }
                    memo[i][eqf][invf] = ans;
                }
            }
        }
        return memo[0][1][0];
    }
};