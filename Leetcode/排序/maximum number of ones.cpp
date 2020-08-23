#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int maximumNumberOfOnes(int width,int height,int sideLength,int maxOnes){
        vector<int> cnt(sideLength * sideLength);
        for(int i =0;i<height;i++){
            for(int j=0;j<width;j++){
                int x = i % sideLength;
                int y = j % sideLength;
                cnt[x*sideLength + y] ++;
            }
        }

        sort(cnt.begin(),cnt.end(),[](int x,int y){
            return x>y;
        });
        int total =0 ;
        for(int i =0;i<maxOnes;i++)
            total+=cnt[i];
        return total;
    }
};