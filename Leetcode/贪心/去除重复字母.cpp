#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeDuplicateLetters(string s) {
        set<char> seen;
        stack<char> st;
        unordered_map<char,int> last_occurence;
        for(int i =0;i<s.size();i++){
            last_occurence[s[i]] = i;
        }
        for(int i =0;i<s.size();i++){
            char c = s[i];
            if(seen.count(c)) continue;
            while(!st.empty() && c<st.top() && i<last_occurence[st.top()]){
                seen.erase(st.top());
                st.pop();
            }
            seen.insert(c);
            st.push(c);
        }
        string res = "";
        while(!st.empty()){
            res.insert(res.begin(),st.top());
            st.pop();
        }
        return res;
    }
};