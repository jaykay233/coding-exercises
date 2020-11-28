class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;
        int a = log(label)/log(2);
        while(label>1){
            res.push_back(label);
            label = (int)(3*pow(2,--a) - label/2-1);
        }
        res.push_back(1);
        reverse(res.begin(),res.end());
        return res;
    }
};