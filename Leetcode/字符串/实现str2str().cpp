class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        vector<int> next = getNext(needle);
        int j = -1;
        for(int i =0; i<haystack.size(); i++){
            while(j!=-1 && needle[j+1]!=haystack[i])
                j = next[j];
            if(needle[j+1] == haystack[i])
                j++;
            if(j == needle.size()-1){
                return i - j;
            }
        }
        return -1;
    }

    vector<int> getNext(string needle){
        int n = needle.size();
        vector<int> next(n,-1);
        int j = -1;
        for(int i=1;i<n;i++){
            while(j!=-1 && needle[j+1]!=needle[i])
                j = next[j];
            if(needle[j+1] == needle[i])
                j++;
            next[i] = j;
        }
        return next;
    }
};