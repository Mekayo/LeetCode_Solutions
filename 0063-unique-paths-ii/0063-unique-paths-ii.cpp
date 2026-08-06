class Solution {
public:
    int rec(vector<vector<int>>& ob, vector<vector<int>>& dp, int r, int c,
            int n,int m) {
        if (r == n - 1 && c == m - 1) return 1;

        if (ob[r][c] == 1) return 0;

        if (dp[r][c] != -1) return dp[r][c];

        int Rcnt = 0, Dcnt = 0;
        if (c < m - 1) {
            Rcnt += rec(ob, dp, r, c + 1, n,m);
        }
        if (r < n - 1) {
            Dcnt += rec(ob, dp, r + 1, c, n,m);
        }
        cout << Rcnt + Dcnt;
        return dp[r][c] = Rcnt + Dcnt;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m= obstacleGrid[0].size();
        if(obstacleGrid[n-1][m-1]==1) return 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return rec(obstacleGrid, dp, 0, 0, n,m);
    }
};