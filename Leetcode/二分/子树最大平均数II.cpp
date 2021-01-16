class Solution {
public:

    bool check(vector<int> nums,int k,double val){
        vector<double> res;
        int n = nums.size();
        for(int i =0;i<n;i++){
            res.push_back((double)nums[i]-val);
        }
        double min_val = 10000;
        double sum=0;
        vector<double> ans(n+1);
        for(int i =0;i<n;i++){
            ans[i+1] = ans[i] + res[i];
            if(i>=k-1){
                min_val = min(min_val,ans[i-(k-1)]);
                if(ans[i+1] >= min_val) return true;
            }
        }
        return false;
    }

    double findMaxAverage(vector<int>& nums, int k) {
        double l = *min_element(nums.begin(),nums.end());
        double r = *max_element(nums.begin(),nums.end());
        while(fabs(r-l)>1e-5){
            double mid = (l+r)/2;
            if(check(nums,k,mid)) l = mid;
            else r = mid;
        }
        return l;
    }
};