#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j;
    string str;
    while(cin>>str){
        int len = str.size();
        for(int i=0;i<len;i++){
            if(len-i>=4){
                string tmp = str.substr(i,4);
                if(tmp == "iPad" || tmp == "iPod") printf("MAI MAI MAI!\n");
                else if(tmp=="Sony") printf("SONY DAFA IS GOOD!\n");
            }
            if(len-i>=5){
                string tmp = str.substr(i,5);
                if(tmp == "Apple") printf("MAI MAI MAI!\n");
            }

            if(len-i>=6){
                string tmp = str.substr(i,6);
                if(tmp == "iPhone") printf("MAI MAI MAI!\n");
            }
        }
    }
    return 0;
}