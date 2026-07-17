class Solution {
public:
    vector<pair<int, int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<vector<bool>> vis(n, vector<bool>(n, 0));
        
        priority_queue<tuple<int, int, int>, 
        vector<tuple<int, int, int>>,
        greater<tuple<int, int, int>> > pq;

        pq.push({grid[0][0], 0, 0});
        //    vis[0][0]=1;

        while (!pq.empty()) {
            auto [eval, x, y] = pq.top();
            pq.pop();
            if (vis[x][y] == 1)
                continue;
            if(x == n - 1 && y == n - 1)
                return eval;
            vis[x][y] = 1;

            for (auto [dr, dc] : direction) {
                int nr = x + dr, nc = y + dc;
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !vis[nr][nc]) {
                    int newval = max(eval, grid[nr][nc]);
                    pq.push({newval, nr, nc});
                }
            }
        }
        return -1;
    }
};