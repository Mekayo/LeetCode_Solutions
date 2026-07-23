class Solution {
public:
    bool isSafe(vector<vector<char>>& mat , int row,int col,char& ch){

        // row
        for(int i=0;i<mat.size();i++){
            if(mat[row][i]==ch) return false;
        }
        // col
        for(int i=0;i<mat.size();i++){
            if(mat[i][col]==ch) return false;
        }
        // 3x3 mat check
        
        int stR=row-row%3;
        int stC=col-col%3;

        for(int i=stR;i<3+stR;i++){
            for(int j=stC;j<3+stC;j++){
                if(mat[i][j]==ch) return false;
            }
        }
    return true;

    }
  bool helper(vector<vector<char>>& mat) {

        int row = -1;
        int col = -1;
        bool isEmpty = true;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (mat[i][j] == '.') {
                    row = i;
                    col = j;
                    isEmpty = false;
                    break;
                }
            }
            if (!isEmpty)
                break;
        }

         
        if (isEmpty)
            return true;

         
        for (char ch = '1'; ch <= '9'; ch++) {

            if (isSafe(mat, row, col, ch)) {

                mat[row][col] = ch;

                if (helper(mat))
                    return true;
                mat[row][col] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};