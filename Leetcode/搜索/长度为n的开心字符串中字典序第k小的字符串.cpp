#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getHappyString(int n, int k) {
        int count = pow(2,n-1);
        vector<char> first_layer={'a','b','c'};
        unordered_map<char,vector<char>> next = { {'a', {'b', 'c'}},{'b', {'a', 'c'}},{'c', {'a', 'b'}} };
        if(k>3*count) return "";
        k--;
        char c = first_layer[k/count];
        k%=count;
        string res = "";
        res += c;
        cout<<res<<endl;
        int left = 0,right = count - 1;
        for(int layer = 1;layer<n;layer++){
            int middle = (left + right) >> 1;
            int leftOrRight = (k>middle)?1:0;
            c = next[c][leftOrRight];
            res += c;
            if(leftOrRight == 0)
                right = middle;
            else 
                left = middle + 1;
        }
        return res;
    }
};