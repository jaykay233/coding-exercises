class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,bool> instack;
        unordered_map<char,int> cnt;
        for(char c:s) cnt[c]++;
        stack<char> st;
        for(char c: s)
        {
            cnt[c] --;
            if(instack[c])
                continue;
            while(!st.empty() && c < st.top())
            {
                if(cnt[st.top()] == 0) break;
                instack[st.top()] = false;
                st.pop();
            }
            st.push(c);
            instack[c] = true;
        }
        string res;
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};