int link[100001] = {0};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int cnt =0 ;   
        memset(link, -1, sizeof link);
        int answ = -1;
        for(int i =0;i<arr.size();i++){
            int pos = arr[i] - 1;
            link[pos] = pos;
            int L = pos, R = pos;
            if(pos>0 && link[pos-1]!=-1){
                if(pos-1-link[pos-1] + 1==m){
                    cnt --;
                }
                L = link[pos-1];
            }
            if(pos+1<arr.size() && link[pos+1]!=-1){
                if(link[pos+1] - (pos+1)+1 == m){
                    cnt--;
                }
                R = link[pos+1];
            }
            link[L] = R;
            link[R] = L;
            if(R-L+1==m){
                cnt++;
            }
            if(cnt>0){
                answ = i + 1;
            }
        }
        return answ;
    }
};