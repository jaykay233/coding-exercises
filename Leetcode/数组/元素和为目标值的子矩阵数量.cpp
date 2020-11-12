class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int total = 0;
        unordered_map<int,int> m;
        for(int c1=0;c1<cols;c1++){
            vector<int> sum(rows,0);
            for(int c2=c1;c2<cols;c2++){
                m.clear();
                m[0] ++;
                int cursum =0,curmax=INT_MIN;
                for(int x=0;x<rows;x++){
                    sum[x] += matrix[x][c2];
                    cursum += sum[x];
                    total += m[cursum-target];
                    m[cursum]++;
                }
            }
        }
        return total;
    }
};