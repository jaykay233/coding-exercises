class Solution {
public:
    int countPrimes(int n) {
        vector<int> primes;
        vector<int> isPrime(n,1);
        for(int i=2;i<n;i++){
            if(isPrime[i]){
                primes.push_back(i);
            }
            for(int j =0;j<primes.size() && i * primes[j] < n;j++){
                isPrime[i * primes[j]] = 0;
                if(i % primes[j] == 0)
                    break;
            }
        }
        return primes.size();
    }
};