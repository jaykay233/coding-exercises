#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int maxn = 5005;
int m,sum=0,len;
char s[maxn];
//尺取法
//先扩展s[x-r]~s[x-l]和s[y+l]~s[y+r]
void work(int x,int y){
    int l=0,r=0,cnt =0;
    while(y+r<len && x-r>=0){
        if(cnt+abs(s[y+r]-s[x-r])<=m){ //先扩展r，再扩展l
            cnt += abs(s[y+r]-s[x-r]);
            r++;
            sum=max(sum,r-l);
        }else{
            cnt -= abs(s[y+l]-s[x-l]);
            l++;
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        sum = 0;
        cin>>m>>s;
        len=strlen(s);
        for(int i=0;i<len;i++){
            work(i,i+1);
            work(i-1,i+1);
        }
        cout<<sum<<endl;
    }
    return 0;
}