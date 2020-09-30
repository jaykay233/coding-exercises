class Solution{
public: 
    int multiply(int A,int B){
        unsigned int a = A;
        int ans = 0;
        while(B){
            if(B&1) ans +=a;
            a+=a;
            B>>=1;
        }
        return ans;
    }
};