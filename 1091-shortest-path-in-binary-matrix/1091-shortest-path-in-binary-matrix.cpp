class Solution {
public:
    vector<pair<int, int>> direction = {{1, 0}, {-1, 0}, {0, 1},  {0, -1},
                                        {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        queue<tuple<int, int, int>> q;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        q.push({0, 0, 1});
        vis[0][0] = 1;

        while (!q.empty()) {
            // using tuple stl fun storing row, col, dist stored in queue

            auto [r, c, dist] = q.front();
            q.pop();

            if (r == n - 1 && c == n - 1)
                return dist;

            for (auto [dr, dc] : direction) { // retriving pair of direstion
                int ni = r + dr, nj = c + dc;

                if (ni >= 0 && ni < n && nj >= 0 && nj < n && !vis[ni][nj] &&
                    grid[ni][nj] == 0) {
                    vis[ni][nj] = 1;
                    q.push({ni, nj, dist + 1});
                }
            }
        }
        return -1;
    }
};
