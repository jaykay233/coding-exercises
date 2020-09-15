typedef long long LL;
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        return binary_search(n,a,b,c);
    }

    LL binary_search(LL n,LL a, LL b, LL c){
        int min_ = min(a,min(b,c));
        int low = min_, high = min_*n;
        while(low<high){
            LL m = (LL)low + high >> 1;
            LL cnt = count(m,a,b,c);
            if(cnt<n) low = m + 1;
            else if(cnt>n) high = m -1;
            else high = m;
        }
        return low;
    }


    LL count(LL num,LL a,LL b,LL c){
        return num/a + num/b + num/c - num/gem(a,b) - num/gem(a,c) - num/gem(b,c) + num/gem(gem(a,b),c);
    }

    LL gem(LL a,LL b){
        return a/gcd(a,b) * b;
    }

    LL gcd(LL a,LL b){
        return b==0?a:gcd(b,a%b);
    }

};