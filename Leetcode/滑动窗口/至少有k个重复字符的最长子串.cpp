class Solution {
public:
    int dfs(string& s,int l, int r, int k)
    {
        vector<int> cnt(26,0);
        for(int i =l;i<=r;i++){
            cnt[s[i] - 'a'] ++ ;
        }
        char split = 0;
        for(int i =0;i<26;i++){
            if(cnt[i] > 0 && cnt[i] < k){
                split = i + 'a';
                break;
            }
        }
        if(split == 0)
            return r - l + 1;
        int i = l;
        int ret =0 ;
        while(i<=r){
            while(i<=r && s[i] == split) i++;
            if(i>r) break;
            int start = i;
            while(i<=r && s[i] != split) i++;
            ret = max(ret, dfs(s, start, i - 1, k));
        }
        return ret;
    }

    int longestSubstring2(string s, int k) {
        int ret = 0;
        int n = s.length();
        for (int t = 1; t <= 26; t++) {
            int l = 0, r = 0;
            vector<int> cnt(26, 0);
            int tot = 0;
            int less = 0;
            while (r < n) {
                cnt[s[r] - 'a']++;
                if (cnt[s[r] - 'a'] == 1) {
                    tot++;
                    less++;
                }
                if (cnt[s[r] - 'a'] == k) {
                    less--;
                }

                while (tot > t) {
                    cnt[s[l] - 'a']--;
                    if (cnt[s[l] - 'a'] == k - 1) {
                        less++;
                    }
                    if (cnt[s[l] - 'a'] == 0) {
                        tot--;
                        less--;
                    }
                    l++;
                }
                if (less == 0) {
                    ret = max(ret, r - l + 1);
                }
                r++;
            }
        }
        return ret;
    }


    int longestSubstring(string s, int k) {
        int n = s.size();
        return dfs(s, 0, n - 1, k);
    }
};