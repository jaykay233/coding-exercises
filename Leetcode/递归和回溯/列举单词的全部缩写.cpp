#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> ans;
    string word;
    string ev;
    vector<string> generateAbbreviations(string word) {
        this->word = word;
        dfs(0);
        return ans;
    }

    void dfs(int s){
        if(s>=word.size()){
            ans.push_back(ev);
            return;
        }
        ev.push_back(word[s]);
        dfs(s+1);
        ev.pop_back();

        for(int i =1;s+i<=word.size();i++){
            string str = to_string(i);
            if(s+i<word.size()) str.push_back(word[s+i]);
            ev += str;
            dfs(s+i+1);
            for(int i =0;i<str.size();i++) ev.pop_back();
        }
    }
};