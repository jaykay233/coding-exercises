#include <vector>
#include <string>
#include <utility>
#include <queue>
using namespace std;
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string s = "";
        priority_queue<pair<int,char>,vector<pair<int,char>>> pq;
        if(c)
            pq.push({c,'c'});
        if(b)
            pq.push({b,'b'});
        if(a)
            pq.push({a,'a'});
        int total = a + b + c;
        for(int i =0;i<total;i++){
            if(pq.empty()) break;
            pair<int,char> p = pq.top();pq.pop();
            if(s.size()<2 || s.size()>=2 && !(s[s.size()-1]==p.second && s[s.size()-2]==p.second) ){
                s += p.second;
                p.first --;
            }else{
                if(pq.empty()) return s;
                pair<int,char> p2 = pq.top();pq.pop();
                s+=p2.second;
                p2.first--;
                if(p2.first>0)
                pq.push(p2);
            }

            if(p.first>0)
                pq.push(p);
        }
        return s;
    }
};