#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    string s;
    for(int len =1;len<=n;len++){
        cin>>s;
        int i = 0, prelen =0 ;
        string str="";
        while(i<s.size()){
            int j = i;
            while(j<s.size() && s[j] == s[i]) j++;
            if(j-i==1){
                str+=s.substr(i,j-i);
                prelen = 1;
            }else if(j-i>=2){
                str+=s.substr(i,2);
                int l = 2;
                if(prelen==2){
                    str.pop_back();
                    l--;
                }
                prelen = l;
            }
            i = j;
        }
        cout<<str<<endl;
    }

    return 0;
}