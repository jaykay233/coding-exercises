class Solution {
public:
    string minWindow(string s, string t) {
        string res = "";
        unordered_map<char,int> m;
        int count = 0;
        for(char c:t) {
            m[c]++;
            count ++;
        }
        int left =0 ;
        int len = s.size() + 1;
        for(int i = 0; i < s.size() ; i++ ){
            if(m[s[i]]-->=1){
                count--;
            }
            while(count==0){
                if(len > i -left + 1){
                    res = s.substr(left, i - left + 1);
                    len = i - left + 1;
                }
                if(m[s[left]]++>=0){
                    count++;
                }
                left++;
            }
        }
        return res;
    }
};