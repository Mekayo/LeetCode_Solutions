class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        for (auto &el : prerequisites){
            adj[el[0]].push_back(el[1]);
        }
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                indegree[adj[i][j]]++;
            }
        }
        vector<int> ans;
        queue<int> q;
        for (int v = 0; v <numCourses; v++) {
            if (!indegree[v])
                q.push(v);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (int k = 0; k < adj[node].size(); k++) {
                indegree[adj[node][k]]--;
                if (indegree[adj[node][k]] == 0) {
                    q.push(adj[node][k]);
                }
            }
        }
        return ans.size() == numCourses;
    }
};