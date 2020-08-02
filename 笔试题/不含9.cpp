#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 30;
LL f[N][9],g[N];

void init(){
    f[0][0] = 1;
    for(int i =0;i+1<N;i++){
        for(int j =0;j<9;j++){
            for(int k =0;k<9;k++){
                f[i+1][(j+k)%9] += f[i][j];
            }
        }
    }

    for(int i =0;i<N;i++){
        for(int j =0;j<9;j++){
            g[i] += f[i][j];
        }
    }
}

LL work(LL n){
    vector<int> nums;
    while(n) nums.push_back(n%10),n/=10;
    LL s =0;
    LL res= 0;
    for(int i =nums.size()-1;i>=0;i--){
        int u = nums[i];
        for(int j =0;j<u;j++){
            int t = (s + j)%9;
            res += g[i] - f[i][(9-t)%9];
        }

        if(u==9){
            s = -1;
            break;
        }
        s += u;
    }
    if(s!=-1 && s%9) res++;
    return res;
}


int main(){
    int T;
    cin>>T;
    init();
    for(int C=1;C<=T;C++){
        LL l,r;
        cin>>l>>r;
        printf("Case #%d: %lld\n", C, work(r) - work(l - 1));
    }

    return 0;
}