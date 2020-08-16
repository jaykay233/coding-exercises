class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> m(26,0);
        for(int i =0;i<order.size();i++) m[order[i]-'a']=i;
        for(int i =0;i<words.size()-1;i++){
            int k =0 ,j=i+1;
            while(k<words[i].size() && k<words[j].size() && words[i][k]==words[j][k]) k++;
            if(k >= words[j].size() || (k < words[i].size() && m[words[i][k] - 'a'] > m[words[j][k] - 'a'])) return false;
        }
        return true;
    }
};
