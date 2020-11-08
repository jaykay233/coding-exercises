#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getIndex(vector<int>& order){
        int n = order.size();
        vector<int> out(n,-1);
        stack<int> st;
        st.push(order[0]);
        for(int i=1;i<n;i++){
            while(!st.empty() && st.top() < order[i]){
                out[st.top()] = order[i];
                st.pop();
            }
            st.push(order[i]);
        }
        return out;
    }

    int oddEvenJumps(vector<int>& A) {
        int ans = 0;
        int n = A.size();
        vector<int> order(n,0);
        for(int i =0;i<n;i++)
            order[i] = i;
        sort(order.begin(),order.end(),[&](int i,int j){
            return A[i]<A[j] || A[i]==A[j] && i<j;
        });
        vector<int> larger = getIndex(order);
        sort(order.begin(),order.end(),[&](int i,int j){
            return A[i]>A[j] || A[i]==A[j] && i<j;
        });
        vector<int> smaller = getIndex(order);
        vector<bool> caneven(n,false);
        vector<bool> canodd(n,false);
        caneven[n-1] = true;
        canodd[n-1] = true;
        for(int i=n-2;i>=0;i--){
            int n1 = larger[i];
            int n2 = smaller[i];
            if(n1!=-1 && caneven[n1]){
                canodd[i] = true;
            }
            if(n2!=-1 && canodd[n2]){
                caneven[i] = true;
            }
        }
        for(int i =0;i<n;i++){
            if(canodd[i]) ans++;
        }
        return ans;

    }
};