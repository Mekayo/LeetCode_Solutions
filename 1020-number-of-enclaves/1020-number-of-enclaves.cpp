class Solution {
public:
    vector<vector<int>> direction = {{1,0},{-1,0},{0,1},{0,-1}};

    int numEnclaves(vector<vector<int>>& grid) {
        int m =grid.size() , n =grid[0].size();

        vector<vector<bool>> vis(m,vector<bool>(n,0));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
                if(grid[i][0]==1){
                    q.push({i,0});
                    vis[i][0]=1;
                }
                if(grid[i][n-1]==1){
                    q.push({i,n-1});
                    vis[i][n-1]=1;
                }
            }
        for(int j=0;j<n;j++){
            if(grid[0][j]==1){
                    q.push({0,j});
                    vis[0][j]=1;
            }
            if(grid[m-1][j]==1){
                    q.push({m-1,j});
                    vis[m-1][j]=1;
                }
            }
    
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(auto &dir:direction){
                int ni=row+dir[0];
                int nj=col+dir[1];

                if(ni>=0 && ni<m && nj>=0 && nj<n && !vis[ni][nj] && grid[ni][nj]==1){
                    vis[ni][nj]=1;
                    q.push({ni,nj});
                }
            }
        }
    int cell_cnt=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j] && grid[i][j]==1){
                cell_cnt++;
            }
        }
    }
    return cell_cnt;
    }
};