class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,1e9));

        for(auto el : edges ){
            int u=el[0];
            int v=el[1];
            int wt=el[2];

            dist[u][v]=wt;
            dist[v][u]=wt;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dist[i][j]= min(dist[i][j], dist[i][k] + dist[k][j]);
                    if(i==j) dist[i][j]=0;                }
            }
        }
        int INF=1e9;
        int res=-1;

        for(int i=0;i<n;i++){

            int cnt=0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=distanceThreshold){
                    cnt++;
                }
            }
            if(cnt< INF){
                INF=cnt;
                res=i;
            }
            else if(cnt==INF) res=i;
        }
        return res;
    }
};