#include <vector>
#include <stack>
using namespace std;
class Solution{
public: 
    int validSubarrays(vector<int>& nums,int res = 0){
        vector<int> s;
        for(auto n:nums){
            while(!s.empty() && n<s.back()) s.pop_back();
            s.push_back(n);
            res += s.size();
        }
        return res;
    }
};