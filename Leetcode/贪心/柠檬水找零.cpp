#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        unordered_map<int,int> m;
        for(int i =0;i<bills.size();i++){
            int b = bills[i];
            if(b==5) {
                m[5]++;
                continue;
            }
            else if(b==10){
                if(m.count(5)){
                    m[5]--;
                    if(m[5]==0)
                        m.erase(5);
                    m[10]++;
                }else 
                    return false;
            }else if(b==20){
                if(m.count(5) && m.count(10)){
                    m[5]--;
                    m[10]--;
                    if(m[5]==0) m.erase(5);
                    if(m[10]==0) m.erase(10);
                    m[20]++;
                }else if(m[5]>=3){
                    m[5]-=3;
                    if(m[5]==0) m.erase(5);
                    m[20]++;
                }else return false;
            }
        }
        return true;
    }
};