class Solution {
public:
    bool checkValidString(string s) {
        int len = s.size();
        int high = 0;
        int low = 0;
        for(int i=0;i<len;i++){
            if(s[i]=='(') {
                high++;
                low++;
            }else if(s[i]==')'){
                high--;
                low--;
            }else if(s[i]=='*'){
                high++;
                low--;
            }
            if(high<0) return false;
            low = max(low,0);
        }
        if(low==0) return true;
        return false;
    }
};