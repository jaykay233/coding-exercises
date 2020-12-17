class Solution {
public:
    int binaryGap(int n) {
        int cnt =0 ;
        int max_cnt =0 ;
        bool start = false;
        while(n){
            int v = n%2;
            // cout<<v<<" "<<cnt<<endl;
            if(v==1){
                if(start)
                    max_cnt = max(max_cnt,cnt);
                if(!start)
                    start = true;
                cnt=0;
            }
            n = n/2;
            cnt++;
        }
        return max_cnt;
    }
};