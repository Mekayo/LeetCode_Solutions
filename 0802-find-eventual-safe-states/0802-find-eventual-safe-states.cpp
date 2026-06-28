class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<vector<int>>rev_graph(v);
        
        vector<int> indegree(v,0);

        for(int i=0;i<graph.size();i++){

            for(auto it:graph[i]){
                rev_graph[it].push_back(i);
                indegree[i]++;
            }
        }
            queue<int> q;
            vector<int> res;
            for(int i=0;i<v;i++){
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            res.push_back(node);
            for(auto &el:rev_graph[node]){
                indegree[el]--;
                if(indegree[el]==0) q.push(el);
            }
        }
    sort(res.begin(),res.end());
    return res;
    }
};