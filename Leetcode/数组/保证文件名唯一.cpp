class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string,int> table;
        vector<string> res;
        for(string& name: names){
            if(table.count(name)){
                for(int k = table[name] + 1; ;k++){
                    string new_name = name + "(" + to_string(k) + ")";
                    if(!table.count(new_name)){
                        res.push_back(new_name);
                        table[name] = k;
                        table[new_name] = 0;
                        break;
                    }
                }
            }
            else{
                table[name] = 0;
                res.push_back(name);
            }
        }
        return res;
    }
};