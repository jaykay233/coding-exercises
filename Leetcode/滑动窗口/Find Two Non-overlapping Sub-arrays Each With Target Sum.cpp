#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        const int kinf = 1e9;
        const int n = arr.size();
        int sum = 0;
        int s = 0;
        int minlen = kinf;
        int ans = kinf;
        vector<int> minlens(arr.size(),kinf);
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            while(sum>target) sum-=arr[s++];
            if(sum==target){
                int curlen = i - s + 1;
                if(s>0 && minlens[s-1]!=kinf ){
                    ans = min(ans,curlen + minlens[s-1]);
                }
                minlen = min(minlen, curlen);
            }
            minlens[i] = minlen;
        }
        return ans>=kinf?-1:ans;
    }
};

int main(){

    return 0;
}