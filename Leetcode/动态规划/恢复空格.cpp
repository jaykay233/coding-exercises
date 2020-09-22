#include <bits/stdc++.h>
using namespace std;

class Trie{
public: 
    Trie* next[26]={nullptr};
    bool isEnd = false;

    Trie(){
        isEnd = false;
    }

    void insert(string word){
        Trie* curPos = this;
        for(int i =word.size()-1;i>=0;i--){
            int t = word[i]-'a';
            if(curPos->next[t]==nullptr)   
                curPos->next[t] = new Trie();
            curPos = curPos->next[t];
        }
        curPos->isEnd = true;
    }
};

class Solution{
public: 
    int respace(vector<string>& dictionary, string sentence){
        int n =sentence.size(),inf = 0x3f3f3f3f;
        Trie* root = new Trie();

        for(string word:dictionary){
            root->insert(word);
        }

        vector<int> dp(n+1,inf);
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            Trie* curPos = root;
            dp[i] = dp[i-1] + 1;
            for(int j =i;j>=1;j--){
                int t = sentence[j-1]-'a';
                if(curPos->next[t]==nullptr)
                    break;
                else if(curPos->next[t]->isEnd)
                    dp[i] = min(dp[i],dp[j-1]);
                curPos = curPos->next[t];
            }
        }
        return dp[n];
    }
};