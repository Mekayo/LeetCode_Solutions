class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);
        for(auto &it : times) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;

        vector<bool> vis(n+1,0);
        vector<int> dist(n+ 1,1e9);
        dist[k]=0;

        pq.push({0,k});
        int reached_nodes=0;

        while(!pq.empty()){
            pair<int,int> top=pq.top();
            int wt=top.first;
            int u=top.second;
            pq.pop();

            if(wt<dist[u]) continue;
            // vis[u]=true;

            for(auto &el : adj[u]){
                int v=el.first;
                int ndw=el.second;

                if(ndw + wt < dist[v]){
                    dist[v]=ndw+wt;
                    pq.push({dist[v],v});
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9) return -1;
            reached_nodes = max(reached_nodes,dist[i]);
        }
        return reached_nodes;
    }
};