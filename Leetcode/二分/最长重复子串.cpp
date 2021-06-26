class Solution {
public:
    bool canRepeat(string s,int len){
        unordered_map<string,int> m;
        for(int i =0;i<s.size();i++){
            string t = s.substr(i,len);
            m[t] ++;
            if(m[t]>=2) return true;
        }
        return false;
    }
    int longestRepeatingSubstring(string s) {
        int l = 1, r = s.size();
        while(l<r){
            int mid = l + r + 1>> 1;
            if(canRepeat(s,mid)) l = mid;
            else r = mid - 1;
        }
        if(canRepeat(s,l)) return l;
        return 0;
    }
};