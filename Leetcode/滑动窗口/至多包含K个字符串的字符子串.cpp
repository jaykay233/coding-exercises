class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char,int> m;
        int l =0 ;
        int max_len = 0;
        for(int i =0;i<s.size();i++){
            m[s[i]]++;
            while(m.size()>k){
                m[s[l]]--;
                if(m[s[l]]==0){
                    m.erase(s[l]);
                }
                l++;
            }
            if(i - l + 1 > max_len){
                max_len = i - l + 1;
            }
        }
        return max_len;
    }
};