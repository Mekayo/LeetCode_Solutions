class Solution {
public:
    vector<vector<int>> direction={{-1,0},{1,0},{0,1},{0,-1}};
    typedef pair<int,int> P;
    void solve(vector<vector<char>>& board) {
        int m= board.size() , n= board[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        queue<P> q;
        
            for(int j=0;j<m;j++){
                if(board[j][0]=='O'){
                    q.push({j,0});
                    vis[j][0] = true;
                }
                if(board[j][n-1]=='O'){
                    q.push({j,n-1});
                    vis[j][n-1] = true;
                }
            }
            for(int j=0;j<n;j++){
                if(board[0][j]=='O'){
                    q.push({0,j});
                    vis[0][j] = true;
                }
                if(board[m-1][j]=='O'){
                    q.push({m-1,j});
                    vis[m-1][j] = true;
                }
            }

        while(!q.empty()){
            P temp=q.front();
            int i=temp.first, j=temp.second;
            q.pop();
            for(auto& dir: direction){
                int ni=i+dir[0];
                int nj=j+dir[1];
                if(ni>=00 && ni<m && nj >=0 && nj < n && !vis[ni][nj] && board[ni][nj]=='O'){
                    vis[ni][nj]=true;
                    q.push({ni,nj});
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j]='X';
                    // vis[i][j]=true;
                }
            }
        }

    }
};