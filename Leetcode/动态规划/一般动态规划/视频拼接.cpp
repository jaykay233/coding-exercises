class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        if(time<=0) return 0;
        sort(clips.begin(),clips.end(),[](vector<int> a,vector<int> b){
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });

        for(int i =0;i<clips.size();i++){
            cout<<clips[i][0]<<":"<<clips[i][1]<<" ";
        }
        cout<<endl;
        int n = clips.size();
        vector<int> dp(n,INT_MAX);
        for(int i =0;i<clips.size();i++){
            if(clips[i][0] == 0) dp[i] = 1;
        }
        int res = INT_MAX;
        for(int i =0;i<clips.size();i++){
            for(int j =0;j<=i;j++){
                if(clips[j][1] >= clips[i][0] && clips[j][1] <= clips[i][1] && dp[j]!=INT_MAX){
                    dp[i] = min(dp[i], dp[j]+1);
                    if(clips[i][1]>=time){
                        res = min(res,dp[i]);
                    }
                }
            }
        }
        return res==INT_MAX?-1:res;
    }
};

