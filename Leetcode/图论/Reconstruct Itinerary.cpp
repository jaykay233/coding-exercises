#include <bits/stdc++.h>
using namespace std;

//解法1 不带回溯版本
class Solution {
public:
    unordered_map<string,multiset<string>> s;
    vector<string> res;
    
    void print(string loc){
        cout<<loc<<" :----"<<endl;
        for(auto it = s[loc].begin();it!=s[loc].end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
        cout<<"---------"<<endl;
    }
    
    
    void dfs(string loc){
        while(s[loc].size()){
            string t = *s[loc].begin();
            s[loc].erase(s[loc].begin());
            dfs(t);
        }
        res.insert(res.begin(),loc);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(vector<string> v:tickets){
            s[v[0]].insert(v[1]);
        }
        dfs("JFK");
        return res;
    }
};

//解法2 带回溯版本

class Solution2 {
public:
    vector<string> res;
    bool dfs(string src,int done,int size,multimap<string,string> m){
        if(done == size) return true;
        if(m.find(src) == m.end()) return false;
         
        vector<decltype(m.begin())> delitrs;  
        auto src_itrs = m.equal_range(src);  
        for(auto itr = src_itrs.first; itr != src_itrs.second; itr++){ delitrs.push_back(itr); }
        sort(begin(delitrs), end(delitrs), [](const auto& itr1, const auto& itr2){ return itr1->second < itr2->second; });
        for(auto& itr : delitrs){  
            res.push_back(itr->second);
            m.erase(itr);
            if(dfs(res.back(), done+1,size,m)) return true;
            m.insert({src, res.back()});
            res.pop_back();
        }
        return false;
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        multimap<string,string> m;
        res.push_back("JFK");
        for(vector<string> v:tickets){
            m.insert({v[0],v[1]});
        }
        dfs("JFK",0,tickets.size(),m);
        return res;
    }
};