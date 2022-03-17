class Solution {
public:
    int front[200005],back[200005];
    int minimumTime(string s) {
        int len = s.size();
        front[0] = s[0] == '0' ? 0 : 1;
        for(int i =1;i<len;i++){
            if(s[i]=='0')
                front[i] = front[i-1];
            else front[i] = min(front[i-1] + 2,i + 1);
        }
        back[len-1]=s[len-1]=='0'?0:1;
        for(int i = len-2;i>=0;i--){
            if(s[i]=='0')
                back[i] = back[i+1];
            else back[i] = min(back[i+1] + 2, len - i);
        }
        int ans=1000000;//充分大即可
        for(int i=0;i<len;i++){
            ans=min(ans,front[i]+back[i+1]);
        }
        return ans;
    }
};