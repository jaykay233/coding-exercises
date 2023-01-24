class Solution {
public:
    int sz;
    unordered_map<int,int> mapping;
    Solution(int n, vector<int>& blacklist) {
        sz = n - blacklist.size();
        for(int b:blacklist)
            mapping[b] = 666;
        int last = n - 1;
        for(int b:blacklist)
        {
            if(b >= sz) continue;
            while(mapping.count(last)){
                last --;
            }
            mapping[b] = last;
            last --;
        }
    }
    
    int pick() {
        int index = rand() % sz;
        if(mapping.count(index))
            return mapping[index];
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */