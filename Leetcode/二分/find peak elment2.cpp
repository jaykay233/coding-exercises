class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row =0 , col = 0;
        int m = mat.size(), n = mat[0].size();
        while(1){
            if(row+1<m && mat[row][col]<mat[row+1][col])
                row++;
            else if(row>0 && mat[row][col] < mat[row-1][col])
                row--;
            else if(col+1<n && mat[row][col] < mat[row][col+1])
                col++;
            else if(col>0 && mat[row][col] < mat[row][col-1])
                col--;
            else return {row,col};
        }
        return {-1,-1};
    }
};

// 作者：jaykay233
// 链接：https://leetcode-cn.com/problems/find-a-peak-element-ii/solution/gan-jing-c-by-jaykay233-5749/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。