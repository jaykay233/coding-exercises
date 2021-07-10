class Solution {
public:
    bool divisorGame(int n) {
        vector<int> f(n+5,false);
        f[1] = false;
        f[2] = true;
        for(int i=3;i<=n;i++){
            for(int j=1;j<i;j++){
                if(i%j==0 && !f[i-j]){
                    f[i] = true;
                    break;
                }
            }
        }
        return f[n];
    }
};