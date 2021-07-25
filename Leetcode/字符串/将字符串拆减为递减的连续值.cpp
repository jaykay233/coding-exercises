class Solution {
public:
    bool splitString(string s) {
        long long now = 0 ;
        for(int i =0;i<s.size()-1;i++){
            now = now * 10 + s[i] - '0';
            if(now>=LLONG_MAX/11) break;
            if(dfs(s,i+1,now-1)) return true;
        }
        return false;
    }

    bool dfs(const string& s,int start, long long value){
        if(start == s.size()) return 1;
        long long now = 0;
        for(int i = start;i<s.size() && now<=value ; i++){
            now = now * 10 + s[i] - '0';
            if(now >= LLONG_MAX / 11) break;
            if(now == 0 && (i<s.size() - 1 ? s[i+1]=='0' : 0)) continue;
            if(now == value){
                return dfs(s, i + 1, value - 1);
            }
        }
        return 0;
    }
};