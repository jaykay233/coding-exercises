class Solution {
public:
    int m,n,k;
    int findKthNumber(int m, int n, int k) {
        this->m = m;
        this->n = n;
        this->k = k;
        int l = 1, r = m * n;
        while(l<r){
            int m = l + r >> 1;
            if(check(m)) r = m;
            else l = m + 1;
        }
        return l;
    }

    bool check(int value){
        int cnt = 0;
        for(int i=1;i<=n;i++){
            int d = value/i;
            d = min(d,m);
            cnt += d;
        }
        return cnt>=k;
    }
};