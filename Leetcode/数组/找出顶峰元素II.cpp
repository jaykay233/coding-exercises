class Solution{
public:
    int maxOfRow(vector<vector<int>>& mat, int row){
        if(row<0 || row>=mat.size()) return -1;
        int col =0 ;
        for(int i = 1;i<mat[row].size();i++){
            if(mat[row][i] > mat[row][col])
                col = i;
        }
        return col;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat){
        int top = 0;
        int down = mat.size() - 1;
        int mid;
        int m1,m2,m3;
        int v1,v2,v3;
        while(top<=down){
            mid = (top + down) >> 1;
            m2 = maxOfRow(mat, mid);
            if(top == down){
                return {mid, m2};
            }
            m1 = maxOfRow(mat, mid-1);
            m3 = maxOfRow(mat, mid+1);
            v1 = mid-1>=0?mat[mid-1][m1] : -1;
            v2 = mat[mid][m2];
            v3 = mid + 1 < mat.size() ? mat[mid+1][m3] : -1;
            if(v2 > v3 && v2 > v1){
                return {mid, m2};
            }
            if(v1 > v3 && v1 >= v2){
                down = mid-1;
            }
            else{
                top = mid + 1;
            }
        }
        return {};
    }
};