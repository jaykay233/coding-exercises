class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        int n = digits.size();
        sort(digits.begin(), digits.end());

        int f[n+1][3];
        memset(f, 0, sizeof f);
        f[0][1]=f[0][2]=-0xffff;  
        for(int i=1; i<=n; ++i){
            for(int j=0; j<3; ++j){
                f[i][j]=max(f[i-1][j], f[i-1][(j+3-digits[i-1]%3)%3]+1);  
            }
        }

        if(f[n][0]<=0) return "";
        string res;
        for(int i=n, j=0; i; --i)
            if(f[i][j]==f[i-1][(j+3-digits[i-1]%3)%3]+1){
                res += to_string(digits[i-1]);
                j = (j+3-digits[i-1]%3)%3;
                if(res=="0") return res;
            }

        return res;      
    }
};
