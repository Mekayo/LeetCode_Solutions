class Solution {
public:
    vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int minimumEffortPath(vector<vector<int>>& heights) {

        int m = heights.size(), n = heights[0].size();

        vector<vector<int>> dist(m, vector<int>(n, 1e9));

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>> , greater<tuple<int, int, int>>> pq;

        pq.push({0, 0, 0});
        dist[0][0] = 0;

        while (!pq.empty()) {
            auto [node, parent, effort] = pq.top();
            pq.pop();

            if(node==m-1 && parent==n-1) return effort;
            if (effort > dist[node][parent])
                continue;

            for (auto dir : direction) {
                int nr = node + dir[0];
                int nc = parent + dir[1];
            
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                int edge = abs(heights[node][parent] - heights[nr][nc]);
                int newEf = max(effort, edge);

                if (newEf < dist[nr][nc]) {
                    dist[nr][nc] = newEf;
                    pq.push({nr,nc,newEf});
                }
            }
        }
    }
    return dist[n-1][m-1];
    }
};