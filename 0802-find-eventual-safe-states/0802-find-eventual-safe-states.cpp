class Solution {
public:
    bool dfs(int node,vector<int>& vis,vector<int>& pathvis,vector<vector<int>>& adj){
        vis[node]=1;
        pathvis[node]=1;

        for(int it:adj[node]){
            if(!vis[it]){
                if((dfs(it,vis,pathvis,adj)==true)){
                    pathvis[node]=1;
                    return true;
                }
            }
            else if(pathvis[it]){
                pathvis[node]=1;
                return true;
            }
        }

    pathvis[node]=0;
    return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);
        vector<int> pathvis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,pathvis,graph);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(vis[i]==1 && pathvis[i]==0) ans.push_back(i);
        }
        return ans;
    }
};