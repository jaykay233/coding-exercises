struct TrieNode{
    TrieNode():is_word(false) {}

    ~TrieNode(){
        for(auto& kv:children)
            if(kv.second) delete kv.second;
    }

    bool is_word;
    unordered_map<char,TrieNode*> children;
    void insert(const string w){
        TrieNode* p = this;
        for(const char c: w){
            if(!p->children.count(c)){
                p->children[c] = new TrieNode();
            }
            p = p->children[c];
        }
        p->is_word = true;
    }
};
class Solution {
public:
    string addBoldTag(string s, vector<string>& words) {
        TrieNode* t = new TrieNode(), *cur;
        for(auto& w:words){
            t->insert(w);
        }
        int n = s.size();
        vector<int> bolded(n,0);
        int boldR = 0;
        for(int i=0,j;i<n;i++){
            cur = t;
            j = i;
            boldR = -1;
            while(j<n && cur->children.count(s[j])){
                cur = cur->children[s[j]];
                if(cur->is_word) boldR = max(boldR,j);
                j++;
            }   
            if(boldR>=i){
                std::fill(bolded.begin()+i,bolded.begin()+boldR+1,1);
            }
        }
        string ans;
        for(int i =0;i<n;i++){
            if(bolded[i] && (i==0 ||!bolded[i-1])) ans +="<b>";
            ans += s[i];
            if(bolded[i] && (i==n-1 || !bolded[i+1])) ans+="</b>";
         }
        return ans;
    }
};