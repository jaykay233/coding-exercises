class Solution {
public:
    vector<vector<int>> direction = {{0,1},{1,0},{0,-1},{-1,0}};
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return {};
        vector<int> res;
        int i =0,j=0;
        int m = matrix.size();
        int n = matrix[0].size();
        int d = 0;
        int total = m*n;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int t =0 ; t<total;++t){
            res.push_back(matrix[i][j]);
            visited[i][j] = true;
            int tmp_i = i + direction[d][0], tmp_j = j + direction[d][1];
            if (tmp_i < 0 || tmp_i >= m || tmp_j < 0 || tmp_j >= n || visited[tmp_i][tmp_j]) {
                d = (d + 1) % 4;
            }
            i += direction[d][0];
            j += direction[d][1];
        }
        return res;
    }
};