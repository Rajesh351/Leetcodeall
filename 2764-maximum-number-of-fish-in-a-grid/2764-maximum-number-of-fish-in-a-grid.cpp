class Solution {
public:
    int n, m;

    int solve(int i, int j, vector<vector<int>>& grid,
              vector<vector<bool>>& vis) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j]==0)
            return 0; // Out of bounds
        if (vis[i][j])
            return 0; // Already visited

        vis[i][j] = true;      // Mark as visited
        int cost = grid[i][j]; // Cost at current cell

        // Recursively explore all 4 directions
        int totalCost = cost + solve(i, j + 1, grid, vis) + // Right
                        solve(i, j - 1, grid, vis) +        // Left
                        solve(i + 1, j, grid, vis) +        // Down
                        solve(i - 1, j, grid, vis);         // Up

        return totalCost;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
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