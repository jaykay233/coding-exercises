class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        vector<vector<int>> res;
        for(string w:words){
            vector<vector<int>> t = kmp(text,w);
            res.insert(res.end(),t.begin(),t.end());
        }
        return res;
    }

    vector<vector<int>> kmp(string text,string word){
        int tlen = text.size();
        int wlen = word.size();
        vector<int> fail(word.size(),-1);
        vector<vector<int>> res;
        for(int i=1,j=-1;i<wlen;i++){
            while(j!=-1 && word[i]!=word[j+1]) j = fail[j];
            if(word[i]==word[j+1]) ++j;
            fail[i] = j;
        }
        for(int i=0,j=-1;i<tlen;i++){
            while(j!=-1 && text[i]!=word[j+1]) j = fail[j];
            if(text[i]==word[j+1]) j++;
            if(j==wlen-1) res.push_back({i-wlen+1,i});
        }
        return res;
    }
};