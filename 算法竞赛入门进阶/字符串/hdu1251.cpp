// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     char str[10];
//     map<string,int> m;
//     while(gets(str)){
//         int len = strlen(str);
//         if(!len) break;
//         for(int i=len;i>0;i--){
//             str[i] = '\0';
//             m[str] ++;
//         }
//     }
//     while(gets(str)) cout<<m[str]<<endl;
//     return 0;
// }

int trie[1000010][26];
int num[1000010]={0};
int pos = 1;
void Insert(char str[]){
    int p = 0;
    for(int i=0;str[i];i++){
        int n = str[i] - 'a';
        if(trie[p][n]==0)
            trie[p][n] = pos++;
        p = trie[p][n];
        num[p] ++;
    }
}

int Find(char str[]){
    int p = 0;
    for(int i=0;str[i];i++){
        int n = str[i] - 'a';
        if(trie[p][n]==0)
            return 0;
        p =  trie[p][n];
    }
    return num[p];
}