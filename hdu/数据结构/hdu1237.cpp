#include <bits/stdc++.h>
using namespace std;
int r(char c){
    switch(c){
        case '#': return 0;
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
        default: return -1;
    }
}

double cal(double a,double b,char c){
    switch(c){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return -1;
    }
}

int main(){
    char s[210];
    int i;
    while(cin.getline(s,sizeof(s))){
        if(strcmp(s,"0")==0) break;
        int len = strlen(s);
        s[len++] = ' ';
        s[len++] = '#';
        s[len] = 0;
        stack<char> f;
        stack<double> dit;
        f.push('#');
        for(int i=0;i<len;i++){
            if(s[i]==' ') continue;
            if(isdigit(s[i])){
                double temp;
                sscanf(s+i,"%lf",&temp);
                dit.push(temp);
                while(isdigit(s[i+1])) i++;
            }
            else{
                bool ok = 1;
                while(ok){
                    if(r(s[i]) > r(f.top()) ){
                        f.push(s[i]);
                        ok = 0;
                    }
                    else{
                        if(s[i]=='#' && f.top()=='#') break;
                        double b = dit.top();dit.pop();
                        double a = dit.top();dit.pop();
                        char c = f.top();f.pop();
                        double d = cal(a,b,c);
                        dit.push(d);
                    }
                }
            }
        }
        double ret = dit.top();
        printf("%.2lf\n",ret);
        while(!f.empty()) f.pop();
        while(!dit.empty()) dit.pop();
    }
    return 0;
}