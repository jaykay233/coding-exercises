/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> d = binaryMatrix.dimensions();
        int r = d[0] - 1;
        int c = d[1] - 1;
        int ans = -1;
        while(r>=0){
            if(binaryMatrix.get(r,c)==1){
                if(c==0) return 0;
                ans = c;
                c--;
            }
            else r--;
        }
        return ans;
    }
};