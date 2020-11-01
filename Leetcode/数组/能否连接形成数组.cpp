class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int,vector<int>> dict;
        for(vector<int>& p:pieces){
            dict[p[0]] = p;
        }

        for(int i =0;i<arr.size();){
            if(!dict.count(arr[i])) return false;
            vector<int> tmp = dict[arr[i]];
            for(int j =0;j<tmp.size();j++,i++){
                if(tmp[j]!=arr[i]) return false;
            }
        }
        return true;
    }
};