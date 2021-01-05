class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> index(26);
        for(int i =0;i<order.size();i++){
            index[order[i]-'a'] = i;
        }
        for(int i =0;i<words.size()-1;i++){
            string word1 = words[i];
            string word2 = words[i+1];
            int j = 0;
            for(;j<min(word1.size(),word2.size());j++){
                if(word1[j]!=word2[j]){
                    if(index[word1[j]-'a'] > index[word2[j]-'a']){
                        return false;
                    }
                    break;
                }
            }
            if(j==min(word1.size(),word2.size()) && word1.size()>word2.size()) return false;
        }
        return true;
    }
};