class Solution {
public:
    int64_t trailingZeroes(int64_t n) {
        int64_t count_five = 0;  
        while(n > 0){  
            int64_t k = n/5;  
            count_five += k;  
            n = k;  
        }  
        return count_five;    
    }
    int64_t getMinimal(int64_t K){
        int64_t start = 0;
        int64_t end = (int64_t)2*INT_MAX;
        while(start <end){
            int64_t pivot = (end+start)/2;
            if(trailingZeroes(pivot) < K)
                start = pivot+1;
            else
                end = pivot;
        }
        return start;
    }
    int64_t preimageSizeFZF(int64_t K) {    return getMinimal(K+1)-getMinimal(K);
    }
};
