#include <iostream>
#include <vector>
#include <cstdio>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution{
public:
    vector<int> majorityElement(vector<int>& nums){
        unordered_map<int,int> m;
        for(int num:nums){
            if(m.count(num)) m[num]++;
            else if(m.size()<3) m[num]++;
            else{
                for(auto p:m){
                    m[p.first]--;
                }
                for(auto it=m.begin();it!=m.end();){
                    if(it->second==0)
                        it = m.erase(it);
                    else
                        it++;
                }
                if(m.size()<3) m[num]++;
            }
        }
        vector<int> cands;
        for(auto p:m)
            cands.push_back(p.first);
        int cnta = 0;
        int cntb = 0;
        int cntc = 0;
        for(int i =0;i<nums.size();i++){
            if(cands.size()>=1)
                if(nums[i]==cands[0]) cnta++;
            if(cands.size()>=2)
                if(nums[i]==cands[1]) cntb++;
            if(cands.size()>=3)
                if(nums[i]==cands[2]) cntc++;
        }
        vector<int> res;
        if(cnta>=nums.size()/3) res.push_back(cands[0]);
        if(cntb>=nums.size()/3) res.push_back(cands[1]);
        if(cntc>=nums.size()/3) res.push_back(cands[2]);
        return res;
    }
};