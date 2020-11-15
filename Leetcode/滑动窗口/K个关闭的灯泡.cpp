class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        vector<int> days(bulbs.size());
        for(int i =0;i<bulbs.size();i++){
            int day = i;
            int position = bulbs[i] - 1;
            days[position] = day;
        }
        int l  =0, r = k + 1;
        int ans = INT_MAX;
        while(r<bulbs.size()){
            bool ok = true;
            int i = l+1;
            for(i =l+1;i<r;i++){
                if(days[i]<days[l] || days[i] < days[r]){
                    l = i;
                    r = i + k + 1;
                    ok = false;
                    break;
                }
            }
            if(ok){
                ans = min(ans,max(days[l],days[r]));
                l = r ;
                r = r + k + 1;
            }
        }
        if(ans==INT_MAX) return -1;
        return ans+1;
    }
};