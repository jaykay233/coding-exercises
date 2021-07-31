class Solution {
public:
    unordered_map<char,int> symbol_values={
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };
    int romanToInt(string s) {
        int ans = 0;
        int len = s.size();
        for(int i =0;i<len;i++){
            int value = symbol_values[s[i]];
            if(i<len-1 && value < symbol_values[s[i+1]]){
                ans -= value;
            }else{
                ans += value;
            }
        }
        return ans;
    }
};