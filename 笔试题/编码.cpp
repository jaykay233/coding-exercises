#include <iostream>
#include <cstdio>
#include <cstring>
#include <unordered_map>
#include <cmath>
using namespace std;

unordered_map<string,int> m;
int n;

void pre(){
    string s = "";
    int idx =0 ;
    while(s!="yyyy"){
        if(s.size()<4){
            s+='a';
        }else{
            int carry = 1;
            s.back()+=carry;
            while(s.size() && s.back()=='z'){
                s.pop_back();
                s.back()+=1;
            }
        }
        m[s] = idx++;
    }
}


int main(){
    pre();
    string s;
    cin>>s;
    int idx = 0;
    string res = "";
    while(idx<s.size()){
        int len = min((int)s.size()-idx,4);
        string x = s.substr(idx,len);
        res+=to_string(m[x]);
        idx+=4;
    }
    cout<<res<<endl;
    return 0;
}