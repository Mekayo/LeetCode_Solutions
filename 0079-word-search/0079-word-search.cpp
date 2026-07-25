class Solution {
private:
    bool find(int row,int col, int at, vector<vector<char>>& board,string word){
        if(at==word.size()) return true;

        if(row<0 || row>=board.size() || col<0 || col>=board[0].size() || board[row][col]=='.' || board[row][col]!=word[at]){
            return false;
        }

        board[row][col]='.';
        bool res = (
        find(row+1,col,at+1,board,word) 
        || find(row-1,col,at+1,board,word)
        || find(row,col+1,at+1,board,word)
        || find(row,col-1,at+1,board,word));
        board[row][col]=word[at];

        return res;
    }
public:

    bool exist(vector<vector<char>>& board, string word) {
         
         int m=board.size();
         int n=board[0].size();
        
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(find(i,j,0,board,word)){
                    return true;
                }
            }
         }
         return false;
    }
};