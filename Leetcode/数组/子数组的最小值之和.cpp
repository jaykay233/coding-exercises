class Solution {
public:
    const int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> stk;
        arr.push_back(0);
        int len = arr.size();
        long res =0 ;
        for(int i =0;i<arr.size();i++){
            while(!stk.empty() && arr[i]<=arr[stk.top()]){
                int index = stk.top();stk.pop();
                int prev_index = -1;
                if(!stk.empty()) prev_index=stk.top();
                int prev_count = index-prev_index-1;
                int next_count = i - index - 1;
                res += long(arr[index]) * (prev_count + 1) * (next_count+1) % mod;
                res %= mod;
            }
            stk.push(i);
        }
        return res;
    }
};