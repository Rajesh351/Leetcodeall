class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
            return -1;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vis[0][0] = true;
        q.push({0, 0});
        int d[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                       {0, 1},   {1, -1}, {1, 0},  {1, 1}};
        int count = 0;
        while (!q.empty()) {
            int size = q.size();  // use a different variable name to avoid conflict
            for (int i = 0; i < size; i++) {
                auto curr = q.front();
                q.pop();
                if (curr[0] == n - 1 && curr[1] == m - 1)
                    return 1 + count;
                for (int j = 0; j < 8; j++) {
                    int nextX = d[j][0] + curr[0];
                    int nextY = d[j][1] + curr[1];
                    if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m && !vis[nextX][nextY] &&
                        grid[nextX][nextY] == 0) {
                        q.push({nextX, nextY});
                        vis[nextX][nextY] = true;
                    }
                }
            }
            count++;
        }
        return -1;
    }
};
