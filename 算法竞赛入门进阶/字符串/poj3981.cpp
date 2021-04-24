#include <cstdio>
using namespace std;
char str[1002];

int main(){
    int i;
    while(gets(str)!=NULL){
        for(int i=0;str[i]!='\n';i++){
            if(str[i]=='y' && str[i+1]=='o' && str[i+2]=='u'){
                printf("we");
                i+=2;
            }else{
                printf("%c",str[i]);
            }
        }
        printf("\n");
    }
    return 0;
}