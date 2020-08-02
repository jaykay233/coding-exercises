#include <iostream>
#include <cstdio>
//马拉车算法
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int center = 0;
        string snew = "#";
        for(int i =0;i<s.size();i++){
            snew+=s[i];
            snew+="#";
        }
        
        int mid = 0;
        int rightmax = 0;
        int len = snew.size();
        vector<int> p(len,1);
        
        for(int i =0;i<len;i++){
            if(i>rightmax){
                p[i] = min(p[2*mid-i],rightmax-i);
            }
            
            while(i+p[i]<len && i-p[i]>=0 && snew[i-p[i]] == snew[i+p[i]])
                p[i]++;
            if(i+p[i]>rightmax){
                rightmax= i+p[i];
                mid = i;
            }
        }
        
        int max_idx =0 ;
        int max_element = 0;
        for(int i=0;i<len;i++){
            if(p[i]>max_element){
                max_element=p[i];
                max_idx = i;
            }
        }
        max_element--;
        snew = snew.substr(max_idx-max_element,max_element*2);
        string res= "";
        for(char c:snew){
            if(c!='#') res+=c;
        }
        return res;
    }
};