class Solution{
public: 
    int trailingZeros(int n){
        int m5=0;
        while(n>0){
            m5+=n/5;
            n/=5;
        }
        return m5;
    }
};