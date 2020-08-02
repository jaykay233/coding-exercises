class Solution {
public:
    int numWays(int n, int k) {
        if(k == 0 || n == 0)
            return 0;
        if(n==1)
            return k;
        int same = k;
        int diff = k*(k-1);
        int temp_diff,temp_same;
        for(int i=3;i<=n;i++){
            temp_same =diff;
            temp_diff = (same + diff) * (k - 1);
            same = temp_same;
            diff =temp_diff;
        }
        return same + diff;
    }
};