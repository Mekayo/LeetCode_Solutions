class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> reverseG(n);
        vector<int> indegree(n,0);

        for(int i=0;i<n;i++){
            for(auto it : graph[i]){
                reverseG[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        vector<int> res;

        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            res.push_back(node);
            for(auto & el :reverseG[node]){
                indegree[el]--;
                if(indegree[el]==0) q.push(el);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};