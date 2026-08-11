class Solution {
public:
    int rec(int i,int j1,int j2,vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int n,int m){
        if(j1<0 || j2<0 || j1>=m || j2>=m){
            return 0;
        }
        if(i==n-1){
            if(j1==j2){
                return grid[i][j1];
            }
            else return grid[i][j1]+grid[i][j2];
        }

        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];

        int maxi=-1e8;

        for(int row =-1;row<=+1;row++){
            for(int col=-1;col<=+1;col++){
              int val=0;
              if(j1==j2) val=grid[i][j1];
              else val=grid[i][j1]+grid[i][j2];
              val+=rec(i+1,j1+row,j2+col,grid,dp,n,m);
              maxi=max(maxi,val);
            }
        }
    return dp[i][j1][j2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        // 3d matrix of d[n][m][m];
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return rec(0,0,m-1,grid,dp,n,m); 
    }
};