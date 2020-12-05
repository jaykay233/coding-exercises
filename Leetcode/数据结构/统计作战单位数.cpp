#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int MAXN = 200+5;
    int c[MAXN];
    vector<int> disc;
    vector<int> iless,imore,kless,kmore;

    int lowbit(int x){
        return x & (-x);
    }

    void add(int p,int v){
        while(p<MAXN){
            c[p] += v;
            p+=lowbit(p);
        }
    }

    int get(int p){
        int r =0 ;
        while(p){
            r += c[p];
            p -= lowbit(p);
        }
        return r;
    }

    int numTeams(vector<int>& rating) {
        disc = rating;
        disc.push_back(-1);
        sort(disc.begin(),disc.end());
        auto getId=[&](int target){
            return lower_bound(disc.begin(),disc.end(),target) - disc.begin();
        };
        iless.resize(rating.size());
        imore.resize(rating.size());
        kless.resize(rating.size());
        kmore.resize(rating.size());
        for(int i =0;i<rating.size();i++){
            auto id = getId(rating[i]);
            iless[i] = get(id);
            imore[i] = get(201) - get(id);
            add(id,1);
        }

        memset(c,0,sizeof(c));
        for(int i=rating.size()-1;i>=0;i--){
            auto id = getId(rating[i]);
            kless[i] = get(id);
            kmore[i] = get(201) - get(id);
            add(id,1);
        }

        int ans = 0;
        for (unsigned i = 0; i < rating.size(); ++i) {
            ans += iless[i] * kmore[i] + imore[i] * kless[i];
        }

        return ans;
    }
};