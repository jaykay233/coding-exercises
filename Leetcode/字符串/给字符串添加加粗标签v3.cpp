class Solution {
public:
    string addBoldTag(string s, vector<string>& words) {
        if(words.empty()) return s;
        int len = s.size();
        vector<bool> bolds(len,false);
        for(string word:words){
            vector<int> next = getNext(word);
            int j = -1;
            for(int i =0;i<s.size();i++){
                while(j!=-1 && word[j+1]!=s[i])
                    j = next[j];
                if(word[j+1] == s[i])
                    j++;
                if(j == word.size()-1){
                    int st = i - j;
                    for(int k = st;k<=i;k++){
                        if(!bolds[k])
                            bolds[k] = true;
                    }
                }
            }
        }
        // cout<<"ok"<<endl;
        string res = "";
        for(int i =0;i<s.size();i++){
            if(i==0 && bolds[i] || i>0 && !bolds[i-1] && bolds[i])
                res += "<b>";
            res += s[i];
            if(i==s.size()-1 && bolds[i] || i+1<bolds.size() && !bolds[i+1] && bolds[i])
                res += "</b>";
        }
        return res;
    }

    vector<int> getNext(string s){
        int len = s.size();
        vector<int> next(len,-1);
        int j = -1;
        for(int i=1;i<len;i++){
            while(j!=-1 && s[j+1]!=s[i])
                j = next[j];
            if(s[j+1] == s[i])
                j++;
            next[i] = j;
        }
        return next;
    }
};