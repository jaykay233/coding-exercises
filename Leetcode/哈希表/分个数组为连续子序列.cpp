class Solution {
public:
    //贪心，努力插到剩余候选集再考虑新开候选集
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> freq;
        unordered_map<int,int> end;
        for(int n:nums) freq[n]++;
        
        for(int n:nums){
            if(freq[n]==0) continue;
            if(end[n-1]>0 && freq[n]>0){
                end[n-1]--;
                freq[n]--;
                end[n]++;
            }else if(freq[n+1]>0 && freq[n+2]>0){
                freq[n+1]--;
                freq[n+2]--;
                freq[n]--;
                end[n+2]++;
            }else return false;
        }
        return true;
    }
};