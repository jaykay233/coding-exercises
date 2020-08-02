#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int scoreOfParentheses(string S) {
        return score(S,0,S.size());    
    }
    
    int score(string S,int i,int j){
        int ans = 0, bar =0 ;
        for(int k=i;k<j;k++){
            if(S[k]=='(') bar+=1;
            else bar -=1;
            if(bar ==0){
                if(k - i==1)
                    ans+=1;
                else
                    ans += 2* score(S,i+1,k);
                i = k+1;
            }
        }
        return ans;
    }
    
};