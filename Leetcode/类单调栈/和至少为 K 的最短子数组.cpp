class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int N = A.size();
        vector<int> P(N+1);
        for(int i =0;i<N;i++) P[i+1]=P[i] + A[i];
        int ans = N+1;
        deque<int> dq;
        //
        for(int i =0;i<P.size();i++){
            while(!dq.empty() && P[i]<=P[dq.back()]) dq.pop_back();
            while(!dq.empty() && P[i]-P[dq.front()]>=K ){
                ans = min(ans,i-dq.front());
                dq.pop_front();
            }
            dq.push_back(i);
        }
        return ans>N?-1:ans;
    }
};