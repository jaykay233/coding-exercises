#include<iostream>
#include<cstdio> 
#include<string>
#include<ctime>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include <unordered_map>
#include<set>
#include<sstream>
using namespace std;
typedef long long LL;
unordered_map<string,int> node;
unordered_map<int,string> shortest;
unordered_map<int,string> longest;
string s;
int w;

void init(){
    int len = s.size();
    for(int i =0;i<len;i++){
        for(int j=1;j+i<=len;j++){
            string sub = s.substr(i,j);
            long long st =0 ;
            for(int k=0;k+j<=len;k++){
                if(s.substr(k,j) == sub){
                    st |= (1LL<<(k+j));
                }
            }
            node[sub] = st;
            if(shortest[st].empty() || j < shortest[st].size())
                shortest[st] = sub;
            if(j > longest[st].size())
                longest[st] = sub;
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
	cin>>s;
    init();
    cin>>w;
    while(w--){
        string s;
		cin>>s;
		LL st=node[s];
		cout<<shortest[st]<<' '<<longest[st];
		int pos=0;
		while(st)
		{
			if(st&1)
				cout<<' '<<pos;
			pos++;
			st>>=1;
		}
		cout<<endl;
    }
    
    return 0;
}