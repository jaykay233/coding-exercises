class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res;
        unordered_set<int> ans;
        for(int i =0;i<arr.size();i++){
            unordered_set<int> tmp;
            tmp.insert(arr[i]);
            for(int t:res){
                tmp.insert(t | arr[i]);
            }
            res = tmp;
            tmp.clear();
            for(int t:res){
                ans.insert(t);
            }
        }
        return ans.size();
    }
};