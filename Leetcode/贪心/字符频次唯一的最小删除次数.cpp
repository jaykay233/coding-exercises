class Solution {
public:
    int minDeletions(string s) {
        vector<int> cnt(26,0);
        for(char c:s) cnt[c-'a'] ++;
        sort(cnt.begin(),cnt.end(),greater<int>());
        int ret=0;
        int prev = cnt[0];
        for(int i=1;i<26 && cnt[i]>0;i++){
            if(prev<=cnt[i]){
                prev = max(prev-1,0);
                ret += cnt[i] - prev;
            }else{
                prev = cnt[i];
            }
        }
        return ret;
    }
};