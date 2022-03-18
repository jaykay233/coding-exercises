class Solution {
public:
    int leastMinutes(int n) {
        int t = 1 ;
        int maxN = 1;
        while(maxN < n) {
            t++;
            maxN *= 2;
        }
        return t;
    }
};