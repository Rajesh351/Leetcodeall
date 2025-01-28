class Solution {
public:
    int rows, cols;

    int solve(int row, int col, vector<vector<int>>& grid,
              vector<vector<bool>>& vis) {
        queue<pair<int,int>>pq;
        pq.push({row,col});
          int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
  int res=0;
    while (!pq.empty()) {
        auto it = pq.front();
        pq.pop();

        int i = it.first;
        int j = it.second;

        // Ensure valid range
        if (i < 0 || j < 0 || i >= rows || j >= cols || vis[i][j] || grid[i][j] == 0)
            continue;

        vis[i][j] = true;  // Mark as visited
        res += grid[i][j];  // Add cost to result

        // Push valid adjacent cells into queue
        for (int d = 0; d < 4; d++) {
            int newX = i + dx[d];
            int newY = j + dy[d];

            if (newX >= 0 && newY >= 0 && newX < rows && newY < cols && !vis[newX][newY] && grid[newX][newY] != 0) {
                pq.push({newX, newY});
            }
        }
    }

         return res;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        rows = grid.size();
        cols= grid[0].size();

        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0 || vis[i][j] == true)
                    continue;

                int ans = solve(i, j, grid, vis);
                res = max(res, ans);
            }
        }
        return res;
    }
};