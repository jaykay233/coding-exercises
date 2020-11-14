//套用数位dp模版，但是由于题目的特殊性，不能直接记忆化
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> digit;
    unordered_map<char, char> m;
    int confusingNumberII(int N) {
        m['0'] = '0';
        m['1'] = '1';
        m['6'] = '9';
        m['8'] = '8';
        m['9'] = '6';
        return solve(N);
    }
    int solve(int n) {
        int len = 0;
        digit.assign(64, 0);
        while (n) {
            digit[++len] = n%10;
            n /= 10;
        }
        string temp;
        return dfs(len, 1, 1, temp);
    }
     int dfs(int pos, bool lead, bool limit, string& num) {
        if(pos == 0){
           return isValid(num);
        }
        int up = limit ? digit[pos]:9;
        int ret = 0;
        for (int i=0; i<=up; ++i) {
            if(!m.count('0' + i)) continue;
            if(lead && (i == 0)){
                ret += dfs(pos-1, 1, limit && (i == up), num);
            }else{
                num += ('0' + i);
                ret += dfs(pos-1, 0, limit && (i == up), num);
                num.pop_back();
            }
        }
        return ret;
    }
    bool isValid(string& num){
        if(num.empty()) return false;
        int i = 0, j = num.length() - 1;
        while(i <= j){
            if(m[num[i]] != num[j]){
                return true;
            }
            i++;
            j--;
        }
        return false;
    }
};
