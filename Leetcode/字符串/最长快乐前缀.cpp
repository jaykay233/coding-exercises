class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> fail(n,-1);
        int j = -1;
        for(int i =1;i<n;i++){
            while(j!=-1 && s[j+1]!=s[i])
                j = fail[j];
            if(s[j+1] == s[i])
                j++;
            fail[i] = j;
        }
        return s.substr(0,fail[n-1] + 1);
    }
};