class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int len = A.size();
        int sum =0;
        int maxsum = INT_MIN;
        for(int i =0;i<len;i++){
            if(sum<0)
                sum = A[i];
            else sum+=A[i];
            maxsum = max(maxsum,sum);
        }
        
        int minsum = INT_MAX;
        sum = 0;
        for(int i =0;i<len;i++){
            sum += A[i];
            if(sum>0)
                sum = 0;
            minsum = min(minsum,sum);
        }
        cout<<maxsum<<" "<<minsum<<endl;
        int total = accumulate(A.begin(),A.end(),0);
        if(minsum!=total) maxsum = max(maxsum,total-minsum);
        return maxsum;
    }
};