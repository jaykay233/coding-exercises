#include <bits/stdc++.h>
using namespace std;

class BIT{
private: 
    int n;
    vector<int> tree;
public: 
    BIT(int n_):n(n_),tree(n_+1){}
    int lowbit(int x){
        return x & (-x);
    }

    void update(int x){
        while(x<=n){
            ++tree[x];
            x+=lowbit(x);
        }
    }

    int query(int x){
        int ans =0 ;
        while(x){
            ans += tree[x];
            x-=lowbit(x);
        }
        return ans;
    }
};


class Solution{
public: 
    const int mod = 1e9+7;
    int createSortedArray(vector<int>& instructions){
        int ub = *max_element(instructions.begin(),instructions.end());
        BIT bit(ub);
        long long ans =0 ;
        for(int i =0;i<instructions.size();i++){
            int x = instructions[i];
            int larger = bit.query(x-1);
            int smaller = i - larger;
            ans += min(larger,smaller);
            bit.update(x);
        }
        return ans % mod;
    }
};