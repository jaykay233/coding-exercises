#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int indegree[26];
    unordered_set<int> s[26];
    string alienOrder(vector<string>& words) {
        unordered_set<char> st;
        for(string word:words){
            for(auto c:word) st.insert(c-'a');
        }
        
        for(int i=0;i+1<words.size();i++){
            string word1 = words[i];
            string word2 = words[i+1];
            for(int i =0;i<min(word1.size(),word2.size());i++){
                if(word1[i]!=word2[i]){
                    if(!s[word1[i]-'a'].count(word2[i]-'a')){
                        s[word1[i]-'a'].insert(word2[i]-'a');
                        indegree[word2[i]-'a']++;
                    }
                    break;
                }
            }
        }
        
        queue<int> q;
        for(int i =0;i<26;i++){
            if(indegree[i]==0 && st.count(i)) q.push(i);
        }        
        
        string w = "";
        while(!q.empty()){
            int t = q.front();q.pop();
            w += ('a' + t);
            for(int n:s[t]){
                indegree[n]--;
                if(indegree[n]==0){
                    q.push(n);
                }
            }
        }
        if(w.size() == st.size()) return w;
        return "";
    }
};