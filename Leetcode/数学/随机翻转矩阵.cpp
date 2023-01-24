class Solution {
public:
    int m;
    int n ;
    int total;
    unordered_map<int,int> mp;
    Solution(int m, int n) {
        total = m * n;
        this->n = n;
        this->m = m;
        srand(time(nullptr));
    }
    
    vector<int> flip() {
        int x = rand() % total;
        vector<int> ans;
        total--;
        if(mp.count(x))
            ans = {mp[x] /n, mp[x] % n};
        else 
            ans = {x/n,x%n};
        if(mp.count(total))
            mp[x] = mp[total];
        else 
            mp[x] = total;
        return ans;
    }   
    
    void reset() {
        total = m * n;
        mp.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */