class Solution {
public:
    unordered_set<string> res;
    vector<string> removeInvalidParentheses(string s) {
        string cands = "";
        dfs(cands, s, 0, 0, 0);
        return vector<string>(res.begin(),res.end());
    }

    void dfs(string cands,string s,int l,int r,int idx){
        if(idx == s.size()){
            if(l == r && (res.empty() || (cands.size() == res.begin()->size())))
                res.insert(cands);
            else if(l == r && (!res.empty() && cands.size() > res.begin()->size())) {
                res.clear();
                res.insert(cands);
            }
            return;
        }
        if(!res.empty() && (cands.size() + s.size() - idx < res.begin()->size())) return;
        char c = s[idx];
        if(c=='('){
            dfs(cands + "(", s, l + 1, r, idx + 1);
            dfs(cands, s, l , r , idx + 1 );
        }else if(c==')'){
            if(l>r){
                dfs(cands + ")", s, l , r + 1, idx + 1);
                dfs(cands, s , l , r, idx + 1);
            }
            if(l == r)
                dfs(cands, s , l , r, idx + 1);
        }else{
            dfs(cands + c, s ,l , r , idx + 1);
        }
    }
};