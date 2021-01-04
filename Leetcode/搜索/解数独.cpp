class Solution {
public:
    bool isValid(vector<vector<char>>& board,int i,int j,char ch){
        for(int k=0;k<9;k++){
            if(board[i][k]==ch) return false;
            if(board[k][j]==ch) return false;
        }
        i = i-i%3;
        j = j-j%3;
        for(int r=0;r<3;r++){
            for(int c=0;c<3;c++){
                if(board[i+r][j+c]==ch) return false;
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(board,0,0);
    }

    bool helper(vector<vector<char>>& board, int i, int j) {
        if (i == 9) return true;
        if (j >= 9) return helper(board, i + 1, 0);
        if (board[i][j] != '.') return helper(board, i, j + 1);
        for (char c = '1'; c <= '9'; ++c) {
            if (!isValid(board, i , j, c)) continue;
            board[i][j] = c;
            if (helper(board, i, j + 1)) return true;
            board[i][j] = '.';
        }
        return false;
    }
};