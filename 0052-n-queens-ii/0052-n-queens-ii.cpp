class Solution {
public:
    bool isSafe(vector<vector<bool>>& mat, int row, int col){
        int n=mat.size();
        for(int i=0;i<row;i++){
            if(mat[i][col]) return 0;
        }
        // left upper diagonal
        int leftend=min(row,col);
        for(int i=1;i<=leftend;i++){
            if(mat[row-i][col-i]) return 0;
        }
        // rightupper diagonal
        int rightend= min(row,n-col-1);
        for(int i=1;i<=rightend;i++){
            if(mat[row-i][col+i]) return 0;
        }
    return 1;
    }

    int helper(vector<vector<bool>> &mat , int row){
        if(row==(int)mat.size()){
            return 1;
        }
        int cnt=0;
        for(int col=0;col<(int)mat.size();col++){
            if(isSafe(mat,row,col)){
                mat[row][col]=1;
                cnt+=helper(mat,row+1);
                mat[row][col]=0;
            }
        }
        return cnt;
    }



    int totalNQueens(int n) {
        vector<vector<bool>> mat(n,vector<bool>(n,0));
        return helper(mat,0);
    }
};