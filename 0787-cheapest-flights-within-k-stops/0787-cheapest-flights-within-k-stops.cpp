class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto el : flights) {
            int u = el[0];
            int v = el[1];
            int wt = el[2];
            adj[u].push_back({v, wt});
        }
        queue<tuple<int, int, int>> q;
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        q.push({0, src, 0});

        while (!q.empty()) {
            auto [st, node, wt] = q.front();
            q.pop();
            // 
            if (st > k)
                continue;
            // 
            for (auto& it : adj[node]) {
                int v = it.first;
                int wgt = it.second;
                if (wgt + wt < dist[v] && st <= k) {
                    dist[v] = wgt + wt;
                    q.push({st + 1, v, wgt + wt});
                }
            }
        }

        if (dist[dst] == 1e9)
            return -1;
        return dist[dst];
    }
};