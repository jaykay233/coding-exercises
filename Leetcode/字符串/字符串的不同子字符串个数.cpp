int trie[250005][26];
class Solution {
public:
    int countDistinct(string s) {
        int ans =0 ;
        int tot = 0;
        int n = s.size();
        
        memset(trie, 0, (n * n * 26 * 4));
        for(int i =0;i<n;i++){
            int curr = 0;
            for(int j =i;j<n;j++){
                int idx = s[j]-'a'; 
                //结点不存在，即对应的子串不存在
                if(!trie[curr][idx]){ trie[curr][idx] = ++tot;
                    ans++;
                }
                curr = trie[curr][idx];
            }
        }
        return ans;
    }
};
