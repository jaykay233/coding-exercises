class Solution {
public:
    int nextGreaterElement(int n) {
        if(n>=INT_MAX) return -1;
        vector<int> res;
        while(n){
            res.push_back(n%10);
            n/=10;
        }
        reverse(res.begin(),res.end());
        int j = res.size() - 2;
        while(j>=0 && res[j] >= res[j+1]) j--;
        if(j==-1) return -1;
        // cout<<j<<endl;
        int k = j + 1;
        while(k<res.size() && res[k] > res[j]) k++;
        k--;
        swap(res[j],res[k]);
        sort(res.begin()+j+1,res.end());
        long long sum = 0;
        for(int r:res){
            sum = sum * 10 + r;
            // cout<<sum<<endl;
        }
        // cout<<sum<<endl;
        if(sum >= pow(2,31)) return -1;
        return sum;
    }
};