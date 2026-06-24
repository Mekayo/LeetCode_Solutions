class Solution {
public:
    vector<vector<int>> direction = {{1,0},{-1,0},{0,1},{0,-1}};
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();

        vector<vector<bool>> vis(m,vector<bool>(n,0));
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
                if(board[i][0]=='O'){
                    q.push({i,0});
                    vis[i][0]=1;
                }
                if(board[i][n-1]=='O'){
                    q.push({i,n-1});
                    vis[i][n-1]=1;
                }
            }
            for(int j=0;j<n;j++){
                if(board[0][j]=='O'){
                    q.push({0,j});
                    vis[0][j]=1;
                }
                if(board[m-1][j]=='O'){
                    q.push({m-1,j});
                    vis[m-1][j]=1;
                }
            }

        while(!q.empty()){
            int row=q.front().first, col=q.front().second;
            q.pop();

            for(auto &dir:direction){
                int new_i=row+dir[0];
                int new_j=col+dir[1];

                if(new_i>=0 && new_i<m && new_j>=0 && new_j<n && !vis[new_i][new_j] && board[new_i][new_j]=='O'){
                    vis[new_i][new_j]=true;
                    q.push({new_i,new_j});
                }
            }
        }
        for(int i = 0 ; i<m ;i++){
            for(int j=0; j <n; j++){
                if(!vis[i][j] && board[i][j]=='O') board[i][j]='X';
            }
        }

    }
};