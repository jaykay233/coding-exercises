class Solution{
public:  
    int numberOf2sInRange(int n){
        return count(n,2);
    }

    int count(int n,int d){
        int high;
        int cnt =0 ;
        for(long long i=1;i<=n;i*=10){
            int k = n/i;
            high = k/10;
            if(d==0){
                if(high!=0)
                    high--;
                else
                    break;
            }
            cnt+=high*i;
            int cur = k%10;
            if(cur>d) cnt+=i;
            else if(cur==d) cnt+=n-i*k+1;
        }
        return cnt;
    }
};