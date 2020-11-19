#include <bits/stdc++.h>
using namespace std;
class AllOne {
public:
    /** Initialize your data structure here. */
    unordered_map<string,list<pair<string,int>>::iterator> mp;
    list<pair<string,int>> m_list;

    AllOne() {

    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(mp.find(key)==mp.end()){
            m_list.push_back({key,1});
            mp[key] = prev(m_list.end());
            return;
        }
        auto it = mp[key];
        ++(it->second);
        auto pit = prev(it);
        while(it!=m_list.begin() && pit->second<it->second){
            iter_swap(pit,it);
            mp[it->first] = it;
            mp[pit->first] = pit;
            it = prev(it);
            pit = prev(pit);
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(mp.count(key)==0)
            return;
        auto it = mp[key];
        --(it->second);
        if(it->second ==0){
            m_list.erase(it);
            mp.erase(key);
            return;
        }
        auto nit = next(it);
        while(nit!=m_list.end() && nit->second > it->second){
            iter_swap(it,nit);
            mp[it->first] = it;
            mp[nit->first] = nit;
            it = next(it);
            nit = next(nit);
        }
        return;
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(m_list.empty()) return "";
        return m_list.front().first;
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(m_list.empty()) return "";
        return m_list.back().first;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */