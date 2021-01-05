class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int min =0,max=1e9;
        vector<int> res={a,b,c};
        sort(res.begin(),res.end());
        a = res[0];
        b = res[1];
        c = res[2];
        max=c-a-2;
        if(b-a==1 && c-b==1)
            min = 0;
        else if(c-b==1 || b-a==1 || b-a==2 || c-b==2){
            min = 1;
        }else min = 2;
        return {min,max};
    }
};