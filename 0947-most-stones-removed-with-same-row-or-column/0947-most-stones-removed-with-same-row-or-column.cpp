class DSU{
public:
    vector<int> rank, parent;
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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        DSU dsu(n);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    dsu.unionbyrank(i,j);
                }
            }
        }
        int groups=0;
        int m = dsu.parent.size();
        for(int i=0;i<m;i++){
            if(i==dsu.parent[i]) groups++;
        }
    return n-groups;
    }
};