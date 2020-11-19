class Solution {
public:
    unordered_map<string,int> m;
    vector<int> sum;
    int stoneGameII(vector<int>& piles) {
        int len = piles.size();
        sum = vector<int>(len);
        sum[len-1] = piles[len-1];
        for(int i=len-2;i>=0;i--)
            sum[i] = sum[i+1] + piles[i];
        return helper(piles,0,1,len);
    }

    int helper(vector<int>& piles,int start,int M,int& len){
        if(len-start<=2*M)
            return sum[start];
        string t = to_string(start) + "-" + to_string(M);
        if(m.count(t)) return m[t];
        int ans =0 ;
        for(int i=1;i<=2*M && i+start<=len;i++){
            ans = max(ans,sum[start] - helper(piles,start+i,max(M,i),len));
        }
        return m[t] = ans;
    }
};