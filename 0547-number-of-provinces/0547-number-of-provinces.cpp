class Solution {
public:
    void dfs(vector<vector<int>> &adj, int i, vector<bool> &vis){
        vis[i]=1;

        for(auto it : adj[i]){
            if(!vis[it])
                dfs(adj,it,vis);
        }
    } 
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                }
            }
        }
        int cnt=0;
        vector<bool> vis(n,0);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(adj,i,vis);
            }
        }
        return cnt;
    }
};