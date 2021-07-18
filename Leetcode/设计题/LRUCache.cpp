#include <bits/stdc++.h>
using namespace std;
class LRUCache {
public:
    unordered_map<int,int> values;
    unordered_map<int,list<int>::iterator> m;
    list<int> l;
    int size;
    LRUCache(int capacity) {
        this->size = capacity;
    }
    
    int get(int key) {
        if(!values.count(key)) return -1;
        int v = values[key];
        put(key,v);
        return v;
    }
    
    void put(int key, int value) {
        if(values.count(key)){
            auto it = m[key];
            l.erase(it);
            l.push_front(key);
            values[key] = value;
            m[key] = l.begin();
            return;
        }else{
            if(l.size()>=this->size){
                int key = l.back();
                values.erase(key);
                m.erase(key);
                l.pop_back();
            }
            l.push_front(key);
            values[key] = value;
            m[key] = l.begin();
        }
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */