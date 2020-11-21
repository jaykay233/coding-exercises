class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        map<int,int> m;
        int ans = 0;
        for (vector<int>& row: grid) {
            for (int c1 = 0; c1 < row.size(); ++c1) if (row[c1] == 1) {
                for (int c2 = c1+1; c2 < row.size(); ++c2) if (row[c2] == 1) {
                    int pos = c1 * 200 + c2;
                    ans += m[pos];
                    m[pos]++;
                }
            }
        }
        return ans;
    }
};