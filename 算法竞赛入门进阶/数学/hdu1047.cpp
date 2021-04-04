#include <bits/stdc++.h>
using namespace std;
int result[1000];

string add(string str1,string str2){
    int l1 = str1.size();
    int l2 = str2.size();
    if(l1>l2){
        for(int i=0;i<l1-l2;i++){
            str2 = "0" + str2;
        }
    }else if(l1<l2){
        for(int i=0;i<l2-l1;i++){
            str1 = "0" + str1;
        }
    }
    l1 = str1.size();
    string str3;
    int c = 0;
    for(int i=l1-1;i>=0;i--){
        int temp = str1[i]-'0' + str2[i]-'0' + c;
        c = temp/10;
        temp = temp%10;
        str3 = char(temp + '0') + str3;
    }
    if(c!=0){
        str3 = char(c+'0') + str3;
    }
    return str3;
}

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        string str;
        string sum = "0";
        while(cin>>str){
            if(str=="0")
                break;
            sum = add(sum,str);
        }
        cout<<sum<<endl;
        if(n>0)
            printf("\n");
    }

    return 0;
}