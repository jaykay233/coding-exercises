#include <bits/stdc++.h>
using namespace std;
class LeaderBoard{
public:
    unordered_map<int,int> m2;
    map<int,set<int>,greater<int>> m1;
    LeaderBoard(){}

    void addScore(int playerId, int score){
        setScore(playerId,m2[playerId]+score);
    }

    int top(int K){
        int sum = 0;
        auto it1 = m1.begin();
        while(K>0){
            int score=it1->first,n=it1->second.size();
            int nToAdd=min(K,n);
            sum+=score*nToAdd;
            K-=nToAdd;
            ++it1;
        }
        return sum;
    }

    void setScore(int id,int score){
        int pre_score = m2[id];
        if(auto it1=m1.begin();it1!=m1.end()) it1->second.erase(id);
        m1[score].insert(id);
        m2[id] = score;
    }

    void reset(int playerId){
        setScore(playerId,0);
    }
};