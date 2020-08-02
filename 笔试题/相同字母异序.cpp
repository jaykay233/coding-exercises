#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int P = 131;

int main(){
    int T;
    scanf("%d",&T);
    for(int cases =1 ;cases<=T;cases++){
        int n;
        string A,B;
        cin>>n>>A>>B;
        unordered_set<ULL> S;
        int s[26];
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                memset(s,0,sizeof s);
                for(int k=i;k<=j;k++) s[B[k]-'A']++;
                ULL hash = 0;
                for(int k=0;k<26;k++) hash = hash * P + s[k];
                S.insert(hash);
            }
        }

        int res =0 ;
        for(int i =0;i<n;i++){
            for(int j=i;j<n;j++){
                memset(s,0,sizeof s);
                for(int k =i;k<=j;k++) s[B[k]-'A']++;
                ULL hash =0 ;
                for(int k =0;k<26;k++) hash = hash * P + s[k];
                if(S.count(hash)) res++;
            }
        }

        printf("Case #%d: %d\n",cases,res);
    }

    return 0;
}