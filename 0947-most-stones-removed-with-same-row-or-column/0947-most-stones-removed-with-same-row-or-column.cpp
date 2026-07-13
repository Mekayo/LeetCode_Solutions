class Solution {
private: 
    void dfs(vector<vector<int>>& stones,int index, vector<bool>& vis){
        vis[index]=1;

        for(int i=0;i<stones.size();i++){
            int row = stones[index][0];
            int col = stones[index][1];
            if((!vis[i]) && (stones[i][0]==row || stones[i][1]==col)){
                dfs(stones, i , vis);
            }
        }
    } 
public:


    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<bool> vis(n,0);

        int components=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(stones,i,vis);
                components++;
            }
        }
        return n-components;
    }
};