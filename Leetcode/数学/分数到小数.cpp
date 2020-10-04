#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(denominator==1) return to_string(numerator);
        if(denominator==-1) return to_string(-(long long)numerator);
        bool sign = false;
        if((numerator<0 && denominator>0) || (numerator>0 && denominator<0)) sign = true;
        numerator = abs(numerator);
        denominator = abs(denominator);
        // cout<<numerator<<" "<<denominator<<endl;
        int zhengshu = numerator/denominator;
        int remain = numerator%denominator;
        if(remain==0) return sign?"-"+to_string(zhengshu):to_string(zhengshu);
        int i =0 ;
        unordered_map<int,int> m;
        string res = "";
        while(remain!=0){
            if(m.count(remain)){
                int idx1 = m[remain];
                res.insert(idx1,"(");
                res.push_back(')');
                break;
            }
            long long r = (long long)remain*10;
            m[remain] = i;
            int val = r/denominator;
            remain = r%denominator;
            res+=to_string(val);
            i++;
        }
        return sign?"-"+to_string(zhengshu)+"."+res : to_string(zhengshu)+"."+res;
    }
};