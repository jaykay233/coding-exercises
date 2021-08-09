class Solution {
public:
    long long pn(int p){
        return (long long)(1 << (p - 1)) * ((1 << p) - 1);
    }
    bool checkPerfectNumber(int num) {
        vector<int> primes = {2,3,5,7,13,17,19};
        for(int prime: primes){
            long long value = pn(prime);
            if(value > num) break;
            if(value > INT_MAX) return false;
            if(value == num) return true;
        }
        return false;
    }
};