class DSU {
private:
    vector<int> rank, parent, size;

public:
    DSU(int n) {
        size.resize(n, 0);
        rank.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

        int findparent(int i) {
            return i == parent[i] ? i : parent[i] = findparent(parent[i]);
        }
        void unionbyrank(int u, int v) {

            int x_p = findparent(u);
            int y_p = findparent(v);

            if (x_p == y_p)
                return;

            if (rank[x_p] > rank[y_p]) {
                parent[y_p] = x_p;
            } else if (rank[y_p] > rank[x_p]) {
                parent[x_p] = y_p;
            } else {
                parent[y_p] = x_p;
                rank[x_p]++;
            }
        }
        void unionbysize(int u, int v) {

            int ul_U = findparent(u);

            int ul_V = findparent(v);

            if (ul_U == ul_V)
                return;

            if (size[ul_U] < size[ul_V]) {

                size[ul_V] += size[ul_U];

                parent[ul_U] = ul_V;

            }

            else {

                size[ul_U] += size[ul_V];

                parent[ul_V] = ul_U;
            }
        }
        int getsize(int node) {
        return size[findparent(node)];
    }

    };
class Solution {
    public:
        vector<pair<int,int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        int largestIsland(vector<vector<int>>& grid) {

            int n = grid.size();

            DSU dsu(n * n);

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if(grid[i][j]==1){
                        int node =i*n+j;
                        for(auto [dr,dc] : direction){
                            int nr=i+dr , nc=j+dc;
                            if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                                int nxtnode=nr*n+nc;
                                dsu.unionbysize(node,nxtnode);
                            }
                        }
                    }
                   
                }
            }
            
            int ans=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==0){
                     unordered_set<int> st;
                    for(auto [dr,dc] : direction){
                            int nr=i+dr , nc=j+dc;
                        if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                            st.insert(dsu.findparent(nr*n+nc));
                        } 
                    }
                    int len = 1; 
                    for(auto &it : st){
                        len += dsu.getsize(it);
                    }
                    ans = max(ans, len);
                }
            }
        }
        
        for(int i=0;i<n*n;i++){
            ans = max(ans, dsu.getsize(i));
        }

        return ans;
        }
};