class Solution {
public:

    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // vector<vector<int>> dist(mat.size(),vector<int>(mat[0].size(),0));
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }
                else
                    mat[i][j]=INT_MAX;
            }
        }

        while(!q.empty()){

            int row=q.front().first, col= q.front().second;
            q.pop();
            for(auto &d:dir){
                int new_i=row+d[0];
                int new_j=col+d[1];

                if(new_i>=0 && new_i<mat.size() &&
                    new_j>=0 && new_j<mat[0].size() && mat[new_i][new_j]>mat[row][col]+1){
                       mat[new_i][new_j]=mat[row][col]+1;
                        q.push({new_i,new_j});
                    }
            }
        }
        return mat;
    }
};