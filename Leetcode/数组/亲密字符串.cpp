class Solution {
public:
    bool buddyStrings(string A, string B) {
        vector<int> idx;
        if(A.size()!=B.size()) return false;
        for(int i=0;i<A.size();i++){
            if(A[i]!=B[i]) idx.push_back(i);
        }
        if(idx.size() && idx.size()!=2) return false;
        if(idx.size()==0){
            unordered_map<char,int> m;
            for(char c:A){
                m[c]++;
                if(m[c]>1) return true;
            }
            return false;
        }
        
        if(A[idx[0]]!=B[idx[1]]) return false;
        if(A[idx[1]]!=B[idx[0]]) return false;
        return true;
    }
};