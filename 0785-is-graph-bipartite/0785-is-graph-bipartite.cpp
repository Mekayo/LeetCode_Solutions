class Solution {

    bool check(int st,int v, vector<vector<int>> &graph, vector<int> &colour){
        queue<int> q;
        q.push(st);
        colour[st]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto &it : graph[node]){
                if(colour[it]==-1){
                    colour[it]= !colour[node];
                    q.push(it);
                }
                else if(colour[it]==colour[node]){
                    return false;
                }
            }
        }
        return true;
    }


public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int> colour(v,-1);

        for(int i=0;i<v;i++){

            if(colour[i]==-1){
                if(check(i,v,graph,colour)==false){
                    return false;
                }
            }
        }
        return true;
    }
};