class Solution {
public:
int timer=1;
    void dfs(int i, int parent , vector<vector<int>>& adj , vector<vector<int>>& ans,vector<bool>& vis,
        vector<int>& tin , vector<int>& low){
        
        vis[i]=1;
        tin[i]=timer;
        low[i]=timer;
        timer++;
        for(auto it : adj[i]){
            if(it==parent) continue;

            if(vis[it]==0){
                dfs(it,i,adj,ans,vis,tin,low);
                low[i]=min(low[it],low[i]);
                if(tin[i]<low[it]){
                    ans.push_back({it,i});
                }
            }
            else{
                low[i]=min(low[i],low[it]);
            }
        }
        
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> tin(n);
        vector<int> low(n);
        
        vector<vector<int>> adj(n);

        for(auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<bool> vis(n,0);
        vector<vector<int>> ans;
        dfs(0,-1,adj,ans,vis, tin, low);
    
    return ans;
    }
};