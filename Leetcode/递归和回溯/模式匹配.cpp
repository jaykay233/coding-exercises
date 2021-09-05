#include <bits/stdc++.h>
using namespace std;
class Solution{
public:  
    std::unordered_map<char,std::string> ch_word;
    std::unordered_set<std::string> words;
    int p_len =0,v_len = 0;
    bool backtrack(const string& pattern, const string& value,int p,int v){
        if(p==p_len) return v== v_len;
        const char& ch = pattern[p];
        if(ch_word.count(ch)){
            const std::string word = ch_word[ch];
            if(word == value.substr(v,word.size()))
                return backtrack(pattern, value ,p + 1, v + word.size());
            else
                return false;
        }

        for(int i = v;i<=v_len;i++){
            string word = value.substr(v, i -v );
            if(words.count(word)) continue;
            words.insert(word);
            ch_word[ch] = word;
            if(backtrack(pattern,value, p + 1, v + word.size())) return true;
            ch_word.erase(ch);
            words.erase(word);
        }
    }

    bool patternMatching(const std::string& pattern, const std::string& value){
        p_len = pattern.size(), v_len = value.size();
        return backtrack(pattern, value, 0, 0);
    }
};