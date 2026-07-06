class Solution {
public:
    const long long mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto &el : roads){
            int u = el[0], v = el[1], wt = el[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        
        vector<long long> times(n, LLONG_MAX);  
        vector<long long> paths(n, 0);

        times[0] = 0;
        paths[0] = 1;
        pq.push({0, 0});

        while(!pq.empty()){
            auto [mintime, node] = pq.top();
            pq.pop();

            if(mintime > times[node]) continue;

            for(auto &it : adj[node]){
                int v = it.first;
                int cur_time = it.second;
                long long newtime = mintime + cur_time;

                if(newtime < times[v]){
                    times[v] = newtime;
                    paths[v] = paths[node] % mod;
                    pq.push({times[v], v});
                }
                else if(newtime == times[v]){
                    paths[v] = (paths[v] + paths[node]) % mod;
                }
            }
        }
        return paths[n-1] % mod;
    }
};
