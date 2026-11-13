class Solution {
public:
    typedef pair<int, int> P;
    vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int m = image.size();
        int n = image[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, 0));
        queue<P> q;
        q.push({sr, sc});
        vis[sr][sc] = 1;

        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                auto temp = q.front();
                q.pop();
                int i = temp.first, j = temp.second;

                for (auto& dir : direction) {
                    int ni = i + dir[0];
                    int nj = j + dir[1];

                    if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
                        image[ni][nj] == image[sr][sc] && !vis[ni][nj]) {
                        image[ni][nj] = color;
                        vis[ni][nj] = 1;
                        q.push({ni, nj});
                    }
                }
            }
        }

        image[sr][sc] = color;
        return image;
    }
};