class DSU{
private:
    vector<int> rank, parent;
public:
    DSU(int n){
        rank.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int findparent(int i){
        return i==parent[i] ? i : parent[i]=findparent(parent[i]);
    }

    void unionbyrank(int x, int y){

        int x_parent=findparent(x);
        int y_parent=findparent(y);

        if(x_parent==y_parent) return;

        if(rank[x_parent] < rank[y_parent]){
            parent[x_parent] = y_parent;
        }
        else if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;
        }
        else{
            parent[y_parent]=x_parent;
            rank[x_parent]+=1;
        }
    return;
    }

};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()< n-1 ){
            return -1;
        }
        DSU dsu(n);
        int count=n;

        for(auto &it :connections ){
            int u=it[0] , v=it[1];

            if(dsu.findparent(u)!= dsu.findparent(v)){
                dsu.unionbyrank(u,v);
                count--;
            }
        }
    return count-1;
    }
};