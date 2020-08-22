#include <vector>
using namespace std;
class Solution{
public:
    const int mod = 1e9+7;
    int rangeSum(vector<int>& nums,int n,int left,int right){
        int i =0,j=1;
        int sum =0 ,ans =0;
        vector<int> v;
        while(i<n){
            sum = 0;
            sum = sum + nums[i];
            v.push_back(sum);
            while(j<n){
                sum = sum + nums[j];
                v.push_back(sum);
                j++;
            }
            i++;
            j=i+1;
        }
        // partial_sort
        partial_sort(v.begin(),v.end()+right,v.end());
        for(int i =left-1;i<right;i++){
            ans = ans + v[i];
            ans = ans % 1000000007;
        }
        return ans;
    }
};