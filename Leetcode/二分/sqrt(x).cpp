#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        while(l<r){
            long long m = (long long)l + r + 1 >> 1;
            if(m<=x/m) l = m;
            else r = m -1;
        }
        return l;
    }
};

int main(){
    return 0;
}