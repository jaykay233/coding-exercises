#include <bits/stdc++.h>
using namespace std;
int n,k;


void change(string& b){
    for(int i=k;i<b.size();i++) b[i] = b[i-k];
}

int main(){
    scanf("%d%d",&n,&k);
    string s;
    cin>>s;
    string a = s;
    change(a);
    if(a>=s){
        cout<<a.size()<<endl<<a<<endl;
        return 0;
    }

    int idx = k-1;
    while(idx>=0 && s[idx]=='9') idx--;
    s[idx] ++;
    idx++;
    while(idx < k) s[idx++] = '0';

    for(int i =k;i<s.size();i++) s[i] = s[i-k];
    cout<<s.size()<<endl;
    cout<<s<<endl;

    return 0;
}